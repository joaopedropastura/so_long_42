/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:36:46 by coder             #+#    #+#             */
/*   Updated: 2022/04/28 16:39:17 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char **static_buffer)
{
	char	*to_new_line;
	size_t	line_size;
	char	*line;
	char	*temp_buffer;

	if (*static_buffer == NULL)
		return (NULL);
	to_new_line = ft_strchr(*static_buffer, '\n');
	if (to_new_line)
	{
		line_size = (to_new_line - *static_buffer) + 1;
		line = ft_substr_gnl(*static_buffer, 0, line_size);
		to_new_line++;
		temp_buffer = ft_strdup(to_new_line);
		free(*static_buffer);
		*static_buffer = ft_strdup(temp_buffer);
		free(temp_buffer);
		return (line);
	}
	else
		return (NULL);
}

static void	assign_line(int bytes, char **stt_buffer, char **buf, char **line)
{
	char	*temp;

	if (bytes > 0)
	{
		if (*stt_buffer == NULL)
			*stt_buffer = ft_strdup("");
		temp = ft_strjoin(*stt_buffer, *buf);
		free(*stt_buffer);
		*stt_buffer = ft_strdup(temp);
		free(temp);
		*line = get_line(stt_buffer);
	}
	free(*buf);
	if (bytes <= 0 && *stt_buffer != NULL)
	{
		if (**stt_buffer != '\0')
			*line = ft_strdup(*stt_buffer);
		free(*stt_buffer);
		*stt_buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	int			bytes_read;
	static char	*static_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(&static_buffer);
	while (line == NULL)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		assign_line(bytes_read, &static_buffer, &buffer, &line);
		if (bytes_read <= 0 && static_buffer == NULL)
			break ;
	}
	return (line);
}
