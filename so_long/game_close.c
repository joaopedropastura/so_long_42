/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:31:28 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/13 02:34:51 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	img_close(t_mapa *mapa, void *image)
// {
// 	mlx_destroy_image(mapa->mlx, image);
// }

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
	mlx_destroy_image(game->mapa.mlx, game->mapa.wall);
	mlx_destroy_image(game->mapa.mlx, game->mapa.floor);
	mlx_destroy_image(game->mapa.mlx, game->mapa.player);
	mlx_destroy_image(game->mapa.mlx, game->mapa.collectable);
	mlx_destroy_image(game->mapa.mlx, game->mapa.exit);
	mlx_destroy_image(game->mapa.mlx, game->mapa.open_exit);
	mlx_destroy_window(game->mapa.mlx, game->mapa.mlx_win);
	mlx_destroy_display(game->mapa.mlx);
	free_map(game->mapa.map);
	free(game->mapa.mlx);
	exit(0);
	return(0);
}