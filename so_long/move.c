/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:15:55 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/04/28 14:48:08 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

typedef struct s_mapa
{
	void	*mlx;
	char	*text;
	int		window_windth;
	int		window_height;
	void	*mlx_win;
	void	*img;
	void	*background_img;
	int		x;
	int		y;
}	t_mapa;

typedef struct s_move
{
	int	eixo_x;
	int eixo_y;
	void	*param;
}	t_move;

void move_to_right(t_move *move)
{
	move->eixo_x += 32;
}
void put_image(t_mapa *mapa, t_move *move);
int	key_do(int key, t_move *move, t_mapa *mapa)
{
	if(key == 'd')
	{
		move_to_right(move);
		put_image(mapa, move);

	}
	if (key == 'p')
		exit(1);
}

void put_image(t_mapa *mapa, t_move *move)
{
	mapa->img = mlx_xpm_file_to_image(mapa->mlx, "img/player-front.xpm", &mapa->x, &mapa->y);
	mlx_put_image_to_window(mapa->mlx, mapa->mlx_win, mapa->img, move->eixo_x, move->eixo_y);
	mlx_key_hook(mapa->mlx_win, key_do, move->param);
	// mlx_loop_hook(mapa->mlx_win, key_do, move->param);
}

int main(void)
{
	t_move walk;
	t_mapa mapa;
	mapa.mlx = mlx_init();
	mapa.mlx_win = mlx_new_window(mapa.mlx, mapa.window_windth, mapa.window_height, mapa.text);
	mapa.background_img = mlx_xpm_file_to_image(mapa.background_img, "img/back-ground.xpm", &mapa.x, &mapa.y);
	mlx_put_image_to_window(mapa.mlx, mapa.mlx_win,mapa.background_img ,0,0);
	mapa.text = "hello world";
	mapa.window_height = 400;
	mapa.window_windth = 400;
	walk.eixo_x = 32;
	walk.eixo_y = 0;
	put_image(&mapa, &walk);
	mlx_loop(mapa.mlx);
	return(0);
}
