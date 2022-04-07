/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 06:40:15 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/04/07 06:50:48 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_lapis
{
	struct s_data *data;
	int		game;
}			t_lapis;

typedef struct s_data
{
	int		window_width;
	int		window_height;
	void	*mlx;
	void	*mlx_win;
	t_lapis	lapis;
}			t_data;

void	print(t_data *data)
{
	data->lapis.game = 10;
	printf("%d%d%d%d", data->window_height, data->window_width, data->lapis.game, data->lapis.data->window_height);

}

int main(void)
{
	t_data data;

	data.window_width = 2;
	data.window_height = 3;
	print(&data);
	return(0);
}
