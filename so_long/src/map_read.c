/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:26:08 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/12 23:36:04 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_line(t_mapa *mapa)
{
	int	i;

	i = 0;
	while (mapa->result[i])
	{
		if (mapa->result[i] == '\n' && mapa->result[i + 1] == '\n')
		{
			free(mapa->result);
			close(mapa->fd);
			mapa->map_height--;
			print_error(ERR_INVALID_MAP);
			return (1);
		}
		i++;
	}
	return (0);
}

int	read_map(t_mapa *mapa, char *path)
{
	mapa->fd = open(path, O_RDONLY);
	if (mapa->fd == -1)
		return (1);
	mapa->result = ft_strdup("");
	mapa->row = get_next_line(mapa->fd);
	mapa->length_base = (int)ft_strlen(mapa->row) - 1;
	while (mapa->row)
	{
		mapa->map_height++;
		mapa->temp = mapa->result;
		mapa->result = ft_strjoin(mapa->temp, mapa->row);
		free(mapa->row);
		free(mapa->temp);
		mapa->row = get_next_line(mapa->fd);
	}
	if (verify_line(mapa) == 1)
		return (1);
	mapa->map = ft_split(mapa->result, '\n');
	free(mapa->result);
	close(mapa->fd);
	return (0);
}
