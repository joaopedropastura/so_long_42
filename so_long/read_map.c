/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:26:08 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/12 23:36:04 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_mapa *mapa, char *path)
{
	int fd;
	char	*result;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	result = ft_strdup("");
	mapa->row = get_next_line(fd);
	mapa->length_base = (int)ft_strlen(mapa->row)-1;
	while(mapa->row)
	{
		mapa->map_height++;
		mapa->temp = result;
		result = ft_strjoin(mapa->temp, mapa->row);
		free(mapa->row);
		free(mapa->temp);
		mapa->row = get_next_line(fd);
	}
	mapa->map = ft_split(result, '\n');
	free(result);
	close(fd);
	return(mapa->map);
}
