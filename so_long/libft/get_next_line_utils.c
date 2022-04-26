/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:31:31 by coder             #+#    #+#             */
/*   Updated: 2022/04/26 23:11:13 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr2(char const *s, unsigned int start, size_t len)
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	len = malloc(size + 1 * sizeof(char));
	if (len == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		len[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		len[i] = s2[j];
		i++;
		j++;
	}
	len[i] = '\0';
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char )c)
			return ((char *)&s[i]);
		i ++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
