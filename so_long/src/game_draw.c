/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:08:05 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/14 17:12:44 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_mapa *mapa, void *image, int x, int y)
{
	mlx_put_image_to_window(mapa->mlx, mapa->mlx_win, image, x * 32, y * 32);
}

int	player_draw(t_game *game)
{
	img_draw(&game->mapa, game->mapa.player, game->player.x, game->player.y);
	return (0);
}

void	exit_draw(t_game *game, int column, int row)
{
	if (game->n_colect == 0)
		img_draw(&game->mapa, game->mapa.open_exit, column, row);
	else
		img_draw(&game->mapa, game->mapa.exit, column, row);
}

int	map_draw(t_mapa *mapa, t_game *game)
{
	int	row;
	int	column;

	row = 0;
	while (mapa->map[row])
	{
		column = 0;
		while (mapa->map[row][column])
		{
			if (mapa->map[row][column] == WALL)
				img_draw(mapa, mapa->wall, column, row);
			else if (mapa->map[row][column] == COLLECTIBLE)
				img_draw(mapa, mapa->collectable, column, row);
			else if (mapa->map[row][column] == MAP_EXIT)
				exit_draw(game, column, row);
			else
				img_draw(mapa, mapa->floor, column, row);
			column++;
		}
		row++;
	}
	return (0);
}

int	game_draw(t_game *game)
{
	map_draw(&game->mapa, game);
	player_draw(game);
	return (0);
}
