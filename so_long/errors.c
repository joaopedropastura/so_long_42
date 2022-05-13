/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:52:32 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/12 22:30:39 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int print_error(int error)
{
	if(error == ERR_INVALID_MAP)
		printf("Error: Invalid map :/\n");
	else if(error == ERR_INVALID_ARGUMENTS)
		printf("Error: Invalid arguments :/\n");
	else if(error == ERR_INVALID_COMPONENTS)
		printf("Error: Invalid components :/\n");
	else if(error == ERR_NO_PLAYER)
		printf("Error: The game must have at least 1 player\n");
	else if(error == ERR_MULTIPLAYER)
		printf("Error: The game must have only 1 player\n");
	else if(error == ERR_NO_COLLECT)
		printf("Error: The game must have at least 1 collectible\n");
	else if(error == ERR_NO_EXIT)
		printf("Error: The game must have an exit\n");
	return(0);
}