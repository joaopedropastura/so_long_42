/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:33:57 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/15 04:33:06 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rows(char *line, t_map *map)
{
	int	length;

	length = (int)ft_strlen(line);
	if (length != map->length_base)
	{
		return (ERR_INVALID_MAP);
	}
	return (0);
}

int	check_components(char *line, t_game *game, int row)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != EMPTY_SPACE && line[i] != WALL && line[i] != COLLECTIBLE
			&& line[i] != PLAYER_POSITION && line[i] != MAP_EXIT)
			return (ERR_INVALID_COMPONENTS);
		if (line[i] == COLLECTIBLE)
			game->n_colect++;
		if (line[i] == MAP_EXIT)
			game->n_exit++;
		if (line[i] == PLAYER_POSITION)
		{
			game->n_player++;
			game->player.x = i;
			game->player.y = row;
		}
		i++;
	}
	return (0);
}

int	check_wall(char *line, t_map *map, int row)
{
	int	i;

	i = 0;
	if (line[i] != WALL || line[map->length_base - 1] != WALL)
		return (ERR_INVALID_ARGUMENTS);
	if (row == 0 || row == map->map_height - 1)
	{
		while (line[i] != '\0')
		{
			if (line[i] != WALL)
				return (ERR_INVALID_ARGUMENTS);
			i++;
		}
	}
	return (0);
}

int	check_minimal_components(t_game *game)
{
	if (game->n_player < 1)
	{
		print_error(ERR_NO_PLAYER);
		return (ERR_NO_PLAYER);
	}
	if (game->n_player > 1)
	{
		print_error(ERR_MULTIPLAYER);
		return (ERR_MULTIPLAYER);
	}
	if (game->n_colect < 1)
	{
		print_error(ERR_NO_COLLECT);
		return (ERR_NO_COLLECT);
	}
	if (game->n_exit < 1)
	{
		print_error(ERR_NO_EXIT);
		return (ERR_NO_EXIT);
	}
	return (0);
}

int	validate_map(t_map *map, t_game *game)
{
	int		i;

	i = 0;
	while (map->map[i])
	{
		if (check_rows(map->map[i], map) == ERR_INVALID_MAP)
			return (print_error(ERR_INVALID_MAP));
		if (check_wall(map->map[i], map, i) == ERR_INVALID_ARGUMENTS)
			return (print_error(ERR_INVALID_ARGUMENTS));
		if (check_components(map->map[i], game, i) == ERR_INVALID_COMPONENTS)
			return (print_error(ERR_INVALID_COMPONENTS));
	i++;
	}
	if (check_minimal_components(game) != 0)
		return (ERR_INVALID_MAP);
	return (VALIDATE_MAP);
}
