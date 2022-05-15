/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:07:31 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/10/09 13:38:21 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*strmapi;

	size = ft_strlen(s);
	i = 0;
	strmapi = malloc(size + 1);
	if (strmapi == NULL)
		return (NULL);
	while (i < size)
	{
		strmapi[i] = f(i, s[i]);
		i ++;
	}
	strmapi[size] = '\0';
	return (strmapi);
}
