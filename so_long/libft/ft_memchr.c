/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:02:27 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/10/07 19:48:00 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;

	chr = (unsigned char)c;
	str = (unsigned char *) s;
	while (n > 0)
	{
		if (*str == chr)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
