/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:16:42 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/24 22:49:12 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	power(int n, int pow)
{
	int	res;

	res = 1;
	while (pow)
	{
		res *= n;
		pow--;
	}
	return (res);
}

static char	*create_str(long n, int size)
{
	char	*res;
	int		i;
	int		p;

	res = (char *) ft_calloc(size + 1, 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n = -n;
		res[i++] = '-';
		size--;
	}
	p = power(10, --size);
	while (p)
	{
		res[i++] = (n / p) + 48;
		n %= p;
		p /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*res;

	size = calc_size(n);
	res = create_str(n, size);
	return (res);
}
