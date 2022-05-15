/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:07:20 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/29 20:32:09 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_base_converter(unsigned long int nbr, char *base)
{
	unsigned long int	aux;
	char				*str;
	int					base_len;
	int					len;

	aux = nbr;
	base_len = ft_strlen(base);
	len = 0;
	if (aux == 0)
		len = 1;
	while (aux)
	{
		aux = aux / base_len;
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (!str[0])
	{
		str[len--] = base[nbr % base_len];
		nbr = nbr / base_len;
	}
	return (str);
}
