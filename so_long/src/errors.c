/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:52:32 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/15 01:23:50 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(int error)
{
	if (error == ERR_INVALID_MAP)
		ft_printf("Error: Invalid map :/\n");
	else if (error == ERR_INVALID_ARGUMENTS)
		ft_printf("Error: Invalid arguments :/\n");
	else if (error == ERR_INVALID_COMPONENTS)
		ft_printf("Error: Invalid components :/\n");
	else if (error == ERR_NO_PLAYER)
		ft_printf("Error: The game must have at least 1 player\n");
	else if (error == ERR_MULTIPLAYER)
		ft_printf("Error: The game must have only 1 player\n");
	else if (error == ERR_NO_COLLECT)
		ft_printf("Error: The game must have at least 1 collectible\n");
	else if (error == ERR_NO_EXIT)
		ft_printf("Error: The game must have an exit\n");
	return (0);
}
