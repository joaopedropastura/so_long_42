/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:17:59 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/15 03:30:51 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_play(t_game *game)
{
	mlx_hook(game->mapa.mlx_win, 2, 1L << 0, check_key, game);
	mlx_hook(game->mapa.mlx_win, 17, 0L, img_close, game);
	mlx_hook(game->mapa.mlx_win, 9, 1L << 21, game_draw, game);
}

int	check_argument(char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		i++;
	}
	if (i < 4)
		return (1);
	if (s[i - 1] != 'r')
		flag++;
	if (s[i - 2] != 'e')
		flag++;
	if (s[i - 3] != 'b')
		flag++;
	if (s[i - 4] != '.')
		flag++;
	if (flag)
		print_error(ERR_INVALID_ARGUMENTS);
	return (flag);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (print_error(ERR_INVALID_ARGUMENTS));
	if (check_argument(argv[1]))
		return (1);
	ft_memset(&game.mapa, '\0', sizeof(t_mapa));
	ft_memset(&game, '\0', sizeof(t_game));
	if (read_map(&game.mapa, argv[1]) == 1)
	{
		print_error(ERR_INVALID_ARGUMENTS);
		return (1);
	}
	if (validate_map(&game.mapa, &game) != VALIDATE_MAP)
		free_map(game.mapa.map);
	else
	{
		game.mapa.mlx = mlx_init();
		game_init(&game.mapa);
		game_draw(&game);
		game_play(&game);
		mlx_loop(game.mapa.mlx);
	}
	return (0);
}
