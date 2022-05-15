/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:26:08 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/15 04:33:06 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_line(t_map *map)
{
	int	i;

	i = 0;
	while (map->result[i])
	{
		if (map->result[i] == '\n' && map->result[i + 1] == '\n')
		{
			free(map->result);
			close(map->fd);
			map->map_height--;
			print_error(ERR_INVALID_MAP);
			return (1);
		}
		i++;
	}
	return (0);
}

int	read_map(t_map *map, char *path)
{
	map->fd = open(path, O_RDONLY);
	if (map->fd == -1)
		return (1);
	map->result = ft_strdup("");
	map->row = get_next_line(map->fd);
	map->length_base = (int)ft_strlen(map->row) - 1;
	while (map->row)
	{
		map->map_height++;
		map->temp = map->result;
		map->result = ft_strjoin(map->temp, map->row);
		free(map->row);
		free(map->temp);
		map->row = get_next_line(map->fd);
	}
	if (verify_line(map) == 1)
		return (1);
	map->map = ft_split(map->result, '\n');
	free(map->result);
	close(map->fd);
	return (0);
}
