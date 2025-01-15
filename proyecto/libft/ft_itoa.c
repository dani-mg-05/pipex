/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:36:54 by damedina          #+#    #+#             */
/*   Updated: 2023/09/27 13:48:37 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(int n)
{
	int	i;
	int	num;

	if (n == -2147483648)
		return (11);
	i = 1;
	num = n;
	if (n < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 9)
	{
		i++;
		num /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		i;

	number = (char *)malloc((num_size(n) + 1) * sizeof (char));
	if (!number)
		return (0);
	i = num_size(n) - 1;
	number[num_size(n)] = '\0';
	if (n == -2147483648)
	{
		number[i--] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		n *= -1;
		number[0] = '-';
	}
	while (n > 9)
	{
		number[i--] = '0' + (n % 10);
		n /= 10;
	}
	number[i] = '0' + n;
	return (number);
}
