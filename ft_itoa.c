/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 07:58:36 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/19 09:47:25 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse_arr(char **arr)
{
	int		i;
	int		len;
	char	tmp;

	len = ft_strlen(*arr) - 1;
	i = 0;
	if ((*arr)[i] == '-')
		i++;
	while (i < len)
	{
		tmp = (*arr)[i];
		(*arr)[i] = (*arr)[len];
		(*arr)[len] = tmp;
		len--;
		i++;
	}
}

static char	*create_str(long n, int is_negative)
{
	char	*res;
	int		i;

	if (n == 0)
	{
		res = (char *) malloc(sizeof(char) * 2);
		if (res == NULL)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res = (char *) malloc(sizeof(char) * 13);
	if (res == NULL)
		return (NULL);
	i = 0;
	if (is_negative)
		res[i++] = '-';
	while (n)
	{
		res[i++] = (n % 10) + '0';
		n /= 10;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		is_negative;
	long	holder;

	is_negative = 0;
	holder = (long) n;
	if (n < 0)
	{
		holder = -holder;
		is_negative = 1;
	}
	res = create_str(holder, is_negative);
	reverse_arr(&res);
	return (res);
}
