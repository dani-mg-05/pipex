/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:52:55 by damedina          #+#    #+#             */
/*   Updated: 2023/09/20 19:10:34 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strs;
	int		i;

	strs = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!strs)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		strs[i] = f(i, s[i]);
	strs[i] = '\0';
	return (strs);
}
