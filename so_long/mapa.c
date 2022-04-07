/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:15:55 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/04/08 00:18:45 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_mapa
{
	void	*mlx;
	char	*text;
	int		window_windth;
	int		window_height;
	void	*mlx_win;
	void	*img;
	int		x;
	int		y;
}	t_mapa;

void put_image(t_mapa *mapa)
{
	mapa->mlx = mlx_init();
	mapa->mlx_win = mlx_new_window(mapa->mlx, mapa->window_windth, mapa->window_height, mapa->text);
	mapa->img = mlx_xpm_file_to_image(mapa->mlx, "img/player-front.xpm", &mapa->x, &mapa->y);
	mlx_put_image_to_window(mapa->mlx, mapa->mlx_win, mapa->img, (400/2)-32, (400/2)-32);
	mlx_loop(mapa->mlx);
}

int main(void)
{
	t_mapa map;
	map.text = "hello world";
	map.window_height = 400;
	map.window_windth = 400;

	put_image(&map);

	return(0);
}
