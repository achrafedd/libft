/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:16:42 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/26 18:28:11 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	calc_size(long n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*res;
	int		min;
	long	holder;

	size = calc_size(n);
	res = (char *) ft_calloc(size + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	min = 0;
	holder = (long) n;
	if (holder < 0)
	{
		holder = -holder;
		res[0] = '-';
		min = 1;
	}
	while (--size >= min)
	{
		res[size] = (holder % 10) + 48;
		holder /= 10;
	}
	return (res);
}
