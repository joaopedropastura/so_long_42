/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:32:15 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/04/28 15:32:22 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char			*lenstr;
	size_t			lens;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup(""));
	lens = ft_strlen(s + start);
	if (lens < len)
		len = lens;
	lenstr = (char *)malloc((len + 1) * sizeof(char));
	if (!lenstr)
		return (NULL);
	while (start != len)
	{
		lenstr[i] = s[start];
		i++;
		start++;
	}
	lenstr[i] = '\0';
	return (lenstr);
}
