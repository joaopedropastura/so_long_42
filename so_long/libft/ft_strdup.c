/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:31:14 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/10/07 19:06:02 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s1);
	i = 0;
	str = malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (len > i)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
