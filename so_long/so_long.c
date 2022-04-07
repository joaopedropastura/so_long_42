/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:17:59 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/04/07 03:57:22 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <unistd.h>


# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 900
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00


typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*adrr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adrr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void write_line(int x, int y, int color)
{

}


int main(void)
{
	t_data str;
	char	*text;

	text = "hello world";
	str.mlx = mlx_init();
	str.mlx_win = mlx_new_window(str.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, text);
	str.img = mlx_new_image(str.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	str.adrr = mlx_get_data_addr(str.img, &str.bits_per_pixel, &str.line_length, &str.endian);
	my_mlx_pixel_put(str.mlx_win, WINDOW_HEIGHT, WINDOW_WIDTH, GREEN_PIXEL);
	mlx_put_image_to_window(str.mlx, str.mlx_win, str.img, 0, 0);
	mlx_loop(str.mlx);
}



