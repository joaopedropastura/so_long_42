/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 01:54:15 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/14 17:18:24 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_game *game, int code)
{
	if (code == K_DOWN && \
		game->mapa.map[game->player.y + 1][game->player.x] != WALL)
			game->player.y++;
	if (code == K_UP && \
		game->mapa.map[game->player.y - 1][game->player.x] != WALL)
			game->player.y--;
	if (code == K_RIGHT && \
		game->mapa.map[game->player.y][game->player.x + 1] != WALL)
			game->player.x++;
	if (code == K_LEFT && \
		game->mapa.map[game->player.y][game->player.x - 1] != WALL)
			game->player.x--;
	if (game->n_colect == 0)
	{
		if (game->mapa.map[game->player.y][game->player.x] == MAP_EXIT)
		{
			img_close(game);
		}
	}
}

void	check_collectable(t_game *game)
{
	if (game->mapa.map[game->player.y][game->player.x] == COLLECTIBLE)
	{
		game->mapa.map[game->player.y][game->player.x] = EMPTY_SPACE;
		game->n_colect--;
	}
	printf("collectables: %i\n", game->n_colect);
}

void	check_step(t_game *game, int code)
{
	if (game->n_colect > 0)
	{
		if (code == K_DOWN && game->mapa.map[game->player.y + 1] \
		[game->player.x] != WALL && code == K_DOWN && game->mapa.map \
		[game->player.y + 1][game->player.x] != MAP_EXIT)
			game->player.y++;
		if (code == K_UP && game->mapa.map[game->player.y - 1] \
		[game->player.x] != WALL && code == K_UP && game->mapa.map \
		[game->player.y - 1][game->player.x] != MAP_EXIT)
			game->player.y--;
		if (code == K_RIGHT && game->mapa.map[game->player.y] \
		[game->player.x + 1] != WALL && code == K_RIGHT && game->mapa.map \
		[game->player.y][game->player.x + 1] != MAP_EXIT)
			game->player.x++;
		if (code == K_LEFT && game->mapa.map[game->player.y] \
		[game->player.x - 1] != WALL && code == K_LEFT && game->mapa.map \
		[game->player.y][game->player.x - 1] != MAP_EXIT)
			game->player.x--;
		check_collectable(game);
	}
	else
		open_exit(game, code);
	game->moves++;
}

void	move_player(t_game *game, int code)
{
	if (code == K_DOWN)
		check_step(game, K_DOWN);
	if (code == K_UP)
		check_step(game, K_UP);
	if (code == K_RIGHT)
		check_step(game, K_RIGHT);
	if (code == K_LEFT)
		check_step(game, K_LEFT);
	game_draw(game);
	printf("movements: %i\n", game->moves);
}

int	check_key(int code, t_game *game)
{
	if (code == ESC || code == K_QUIT)
		img_close(game);
	move_player(game, code);
	return (0);
}
