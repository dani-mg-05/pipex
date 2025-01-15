/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:24:16 by damedina          #+#    #+#             */
/*   Updated: 2023/09/27 13:46:24 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		encontrado;

	i = 0;
	encontrado = 0;
	while (!encontrado && i < ft_strlen(s1))
	{
		j = 0;
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
				j = ft_strlen(set) + 2;
			j++;
		}
		if (j == ft_strlen(set))
			encontrado = 1;
		i++;
	}
	return (i - 1);
}

static size_t	end(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		encontrado;

	i = ft_strlen(s1) - 1;
	encontrado = 0;
	while (!encontrado && i > 0)
	{
		j = 0;
		while (j < (int)ft_strlen(set))
		{
			if (s1[i] == set[j])
				j = (int)ft_strlen(set) + 2;
			j++;
		}
		if (j == (int)ft_strlen(set))
			encontrado = 1;
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	istart;
	size_t	iend;

	if (!s1 || !set)
		return (NULL);
	istart = start(s1, set);
	iend = end(s1, set);
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	if (s1[0] == '\0' || s1 == set || istart > iend)
		return (ft_strdup(""));
	str = (char *)malloc((iend - istart + 2) * sizeof (char));
	if (!str)
		return (0);
	ft_strlcpy(str, &s1[istart], iend - istart + 2);
	return (str);
}
