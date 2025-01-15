/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:49:07 by damedina          #+#    #+#             */
/*   Updated: 2023/09/27 13:21:50 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (void *)s;
	while (i < n && str[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (0);
	if (str[i] == (unsigned char)c)
		return (&str[i]);
	return (0);
}
