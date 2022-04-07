/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:01:48 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/04/07 06:37:12 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <so_long.h>
#include <mlx.h>
# define WIDTH 800
# define HEIGHT 800

typedef	struct	s_data
{
	int		window_width;
	int		window_height;
	void	*mlx;
	void	*mlx_win;
}			t_data;

void *draw_pixel(t_data *data, int x, int y, int color)
{

}

int main(void)
{
	int		x = 0;
	void	*mlx;
	void	*mlx_win;
	char	*title;
	void	*mlx_pixel;

	title = "piroquinha de mel";
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, title);
	while(x != HEIGHT)
	{
		mlx_pixel_put(mlx, mlx_win, WIDTH/2, x, 0xFF00);
		x++;
		// mlx_pixel_put(mlx, mlx_win, WIDTH, y, 0xFF00);
		// y++;
	}
	mlx_loop(mlx);
}
