/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:25:15 by damedina          #+#    #+#             */
/*   Updated: 2023/09/27 13:37:09 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = (char *)malloc((ft_strlen(s1) + 1) * sizeof (char));
	if (!dst)
		return (0);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}
