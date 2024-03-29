/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:59:03 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/15 04:33:06 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define PLAYER_POSITION 'P'
# define ESC		65307
# define K_UP		119
# define K_DOWN		115
# define K_LEFT		97
# define K_RIGHT	100
# define K_QUIT		113

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	int		map_width;
	int		map_height;
	int		x_img;
	int		y_img;
	char	**map;
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectable;
	void	*exit;
	void	*open_exit;
	char	*row;
	char	*temp;
	char	*result;
	int		fd;
	int		length_base;
	void	*back_ground_img;
}	t_map;

typedef struct s_player_position {
	int		x;
	int		y;
}	t_player_position;

typedef struct s_game
{
	t_map				map;
	t_player_position	player;
	int					n_colect;
	int					n_player;
	int					n_exit;
	int					moves;
}	t_game;

typedef enum e_error {
	ERR_READ_MAP,
	ERR_INVALID_ARGUMENTS,
	ERR_INVALID_MAP,
	ERR_MULTIPLAYER,
	ERR_NO_COLLECT,
	ERR_NO_EXIT,
	ERR_NO_PLAYER,
	ERR_INVALID_COMPONENTS,
	VALIDATE_MAP,
}	t_error;

int		print_error(int error);
int		read_map(t_map *map, char *path);
int		validate_map(t_map *map, t_game *game);
int		check_minimal_components(t_game *game);
int		check_components(char *line, t_game *game, int row);
int		check_wall(char *line, t_map *map, int row);
int		render_map(t_map *map);
void	game_init(t_map *map);
void	img_draw(t_map *map, void *image, int x, int y);
int		map_draw(t_map *map, t_game *game);
void	load_img(t_map *map);
int		player_draw(t_game *game);
int		check_key(int code, t_game *game);
void	move_player(t_game *game, int code);
int		img_close(t_game *game);
int		game_draw(t_game *game);
void	free_map(char **map);
int		verify_line(t_map *map);

#endif
