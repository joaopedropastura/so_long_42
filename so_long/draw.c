/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:08:05 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/10 04:39:58 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	img_draw(t_mapa *mapa, void *image, int x, int y)
// {
// 	mlx_put_image_to_window(mapa->mlx, mapa->mlx_win, image, x * 32, y * 32);
// }
void map_draw(t_mapa *mapa)
{
	int row;
	int column;

	row = 0;
	while(mapa->map[row])
	{
		column = 0;
		while(mapa->map[row][column])
		{
			if (mapa->map[row][column] == WALL)
				mlx_put_image_to_window(mapa->map, mapa->mlx_win, mapa->wall, column, row);
			if(mapa->map[row][column] == EMPTY_SPACE)
				mlx_put_image_to_window(mapa->map, mapa->mlx_win, mapa->floor, column, row);
			if(mapa->map[row][column] == COLLECTIBLE)
				mlx_put_image_to_window(mapa->map, mapa->mlx_win,  mapa->collectable, column, row);
			if(mapa->map[row][column] == MAP_EXIT)
				mlx_put_image_to_window(mapa->map, mapa->mlx_win, mapa->exit, column, row);
			if(mapa->map[row][column] == PLAYER_POSITION)
				mlx_put_image_to_window(mapa->map, mapa->mlx_win, mapa->player, column, row);
			column++;
		}
		row++;
	}
}