/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:50:14 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/15 04:33:06 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	img_close(t_game *game)
{
	mlx_destroy_image(game->map.mlx, game->map.wall);
	mlx_destroy_image(game->map.mlx, game->map.floor);
	mlx_destroy_image(game->map.mlx, game->map.player);
	mlx_destroy_image(game->map.mlx, game->map.collectable);
	mlx_destroy_image(game->map.mlx, game->map.exit);
	mlx_destroy_image(game->map.mlx, game->map.open_exit);
	mlx_destroy_window(game->map.mlx, game->map.mlx_win);
	mlx_destroy_display(game->map.mlx);
	free_map(game->map.map);
	free(game->map.mlx);
	exit(0);
	return (0);
}
