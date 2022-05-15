/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:55:21 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/11/29 20:12:40 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_digits_ulen(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = MAX_LONG_INT - (n * -1);
		return (len);
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char				*result;
	unsigned int		len;
	unsigned int		number;

	len = ft_digits_ulen(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		number = MAX_LONG_INT - (n * -1);
		result[0] = '-';
	}
	else
		number = n;
	while (number > 0)
	{
		result[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (result);
}
