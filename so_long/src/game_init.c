/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:26:51 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/15 04:33:06 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_map *map)
{
	map->wall = mlx_xpm_file_to_image
		(map->mlx, "img/wall.xpm", &map->x_img, &map->y_img);
	map->player = mlx_xpm_file_to_image
		(map->mlx, "img/player-front.xpm", &map->x_img, &map->y_img);
	map->floor = mlx_xpm_file_to_image
		(map->mlx, "img/back-ground.xpm", &map->x_img, &map->y_img);
	map->exit = mlx_xpm_file_to_image
		(map->mlx, "img/exit.xpm", &map->x_img, &map->y_img);
	map->collectable = mlx_xpm_file_to_image
		(map->mlx, "img/collectable.xpm", &map->x_img, &map->y_img);
	map->open_exit = mlx_xpm_file_to_image
		(map->mlx, "img/open-exit.xpm", &map->x_img, &map->y_img);
}

void	game_init(t_map *map)
{
	int	height;
	int	width;

	height = map->map_height * 32;
	width = map->length_base * 32;
	map->mlx_win = mlx_new_window(map->mlx, width, height, "so_long");
	load_img(map);
}
