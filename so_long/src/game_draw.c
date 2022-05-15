/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:08:05 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/15 04:33:06 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_map *map, void *image, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, image, x * 32, y * 32);
}

int	player_draw(t_game *game)
{
	img_draw(&game->map, game->map.player, game->player.x, game->player.y);
	return (0);
}

void	exit_draw(t_game *game, int column, int row)
{
	if (game->n_colect == 0)
		img_draw(&game->map, game->map.open_exit, column, row);
	else
		img_draw(&game->map, game->map.exit, column, row);
}

int	map_draw(t_map *map, t_game *game)
{
	int	row;
	int	column;

	row = 0;
	while (map->map[row])
	{
		column = 0;
		while (map->map[row][column])
		{
			if (map->map[row][column] == WALL)
				img_draw(map, map->wall, column, row);
			else if (map->map[row][column] == COLLECTIBLE)
				img_draw(map, map->collectable, column, row);
			else if (map->map[row][column] == MAP_EXIT)
				exit_draw(game, column, row);
			else
				img_draw(map, map->floor, column, row);
			column++;
		}
		row++;
	}
	return (0);
}

int	game_draw(t_game *game)
{
	map_draw(&game->map, game);
	player_draw(game);
	return (0);
}
