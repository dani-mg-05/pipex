/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:19:08 by damedina          #+#    #+#             */
/*   Updated: 2023/09/27 13:34:57 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (str2[0] == '\0' || str1 == str2)
		return (str1);
	while (i < len && str1[i] != '\0')
	{
		j = 0;
		while (i < len && str1[i] == str2[j] && str2[j] != '\0')
		{
			i++;
			j++;
		}
		if (str2[j] == '\0' && str1[i - 1] == str2[j - 1])
			return (&str1[i - j]);
		i = i - j + 1;
	}
	return (0);
}
