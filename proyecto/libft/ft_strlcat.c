/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:18:59 by damedina          #+#    #+#             */
/*   Updated: 2023/09/27 13:16:21 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idst;
	size_t	isrc;
	size_t	size_dst;

	size_dst = ft_strlen(dst);
	if (dstsize < ft_strlen(dst) || (dstsize == 0 && dst[0] == '\0'))
		return (dstsize + ft_strlen(src));
	idst = size_dst;
	isrc = 0;
	while (idst < dstsize - 1 && src[isrc] != '\0')
	{
		dst[idst] = src[isrc];
		idst++;
		isrc++;
	}
	dst[idst] = '\0';
	return (ft_strlen(src) + size_dst);
}
