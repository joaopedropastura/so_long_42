/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:27:05 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/10/12 19:24:59 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*lenstr;
	size_t	lens;

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
	ft_strlcpy(lenstr, &s[start], len + 1);
	return (lenstr);
}
