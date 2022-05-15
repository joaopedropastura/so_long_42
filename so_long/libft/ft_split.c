/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:54:52 by jpedro-s          #+#    #+#             */
/*   Updated: 2021/10/12 19:23:22 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i ++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = ft_calloc(sizeof(char *), count_word(s, c) + 1);
	if (split == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] != c && s[j] != '\0')
		{
			split[i] = ft_substr(s, j, word(s + j, c));
			i++;
			j = j + word(s + j, c);
		}
	}
	return (split);
}
