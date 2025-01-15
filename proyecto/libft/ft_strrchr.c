/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:01:46 by damedina          #+#    #+#             */
/*   Updated: 2023/09/27 13:19:25 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = ft_strlen(s);
	str = (char *)s;
	if (str && (unsigned char)c == '\0')
		return (&str[i]);
	while (str[i] != (unsigned char)c && i != 0)
		i--;
	if (i == 0 && str[i] != (unsigned char)c)
		return (0);
	return (&str[i]);
}
