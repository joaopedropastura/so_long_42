/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:26:51 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/13 02:32:57 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_mapa *mapa)
{
	mapa->wall = mlx_xpm_file_to_image
	(mapa->mlx, "img/wall.xpm", &mapa->x_img, &mapa->y_img);
	mapa->player = mlx_xpm_file_to_image
	(mapa->mlx, "img/player-front.xpm", &mapa->x_img, &mapa->y_img);
	mapa->floor = mlx_xpm_file_to_image
	(mapa->mlx, "img/back-ground.xpm",  &mapa->x_img, &mapa->y_img);
	mapa->exit = mlx_xpm_file_to_image
	(mapa->mlx, "img/exit.xpm",  &mapa->x_img, &mapa->y_img);
	mapa->collectable = mlx_xpm_file_to_image
	(mapa->mlx, "img/collectable.xpm",  &mapa->x_img, &mapa->y_img);
	mapa->open_exit = mlx_xpm_file_to_image
	(mapa->mlx, "img/open-exit.xpm",  &mapa->x_img, &mapa->y_img);
}

void	game_init(t_mapa *mapa)
{
	int height;
	int width;

	height = mapa->map_height * 32;
	width = mapa->length_base * 32;
	mapa->mlx_win = mlx_new_window(mapa->mlx, width, height,"so_long");
	// free(mapa->length_base);
	// free(mapa->map_height);
	// game->moves = 0;
	// game->player.x *= 32;
	// game->player.y *= 32;
	load_img(mapa);
}