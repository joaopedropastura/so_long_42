/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:17:59 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/10 04:40:51 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int i, j;
	(void)argc;
	i = 0;
	j = 0;
	t_mapa mapa;
	t_game game;
	ft_memset(&mapa, '\0', sizeof(t_mapa));
	ft_memset(&game, '\0', sizeof(t_game));
	read_map(&mapa, argv[1]);
	validate_map(&mapa, &game);
	printf("%s\n", argv[1]);
	while(mapa.map[i][j])
	{
		printf("%c",mapa.map[1][j]);
		j++;
	}
	printf("%s\n", argv[1]);
	mapa.mlx = mlx_init();
	game_init(&mapa, &game);
	mlx_put_image_to_window(mapa.map, mapa.mlx_win, mapa.wall, 0, 0);
	// map_draw(&mapa);
	mlx_loop(mapa.mlx);
}

// int main(void) {
//   char *row;
//   char **mapa;
//   char *tmp;

//   int fd;

//   fd = open("solong", O_RDONLY);
//   row = ft_strdup("");
//   tmp = ft_strdup("");

//   tmp = get_next_line(fd);
//   while (tmp) {
//     row = ft_strjoin(row, tmp);
//     printf("%s\n", row);
//     free(tmp);
//     tmp = get_next_line(fd);
//   }
//   printf("%s", row);
//   mapa = ft_split(row, '\n');
//   for (int i = 0; mapa[i] != NULL; i++)
//     printf("linha %d - %s\n", i, mapa[i]);
// }


