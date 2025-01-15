/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:29:06 by damedina          #+#    #+#             */
/*   Updated: 2023/09/27 13:47:32 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

static char	**free_malloc(char **strs, int i)
{
	while (--i >= 0)
		free (strs[i]);
	free (strs);
	return (0);
}

static char	**ft_split_aux(char const *s, char c, char **strs)
{
	int		i;
	size_t	size;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				size = ft_strlen(s);
			else
				size = ft_strchr(s, c) - s;
			strs[i] = ft_substr(s, 0, size);
			if (!strs[i])
				return (free_malloc(strs, i));
			s = s + size;
			i++;
		}
	}
	strs[i] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	strs = (char **)malloc((num_words(s, c) + 1) * sizeof (char *));
	if (!strs || !s)
		return (0);
	return (ft_split_aux(s, c, strs));
}
