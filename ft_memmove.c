/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:39:33 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/24 20:34:54 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	c1 = (unsigned char *) dest;
	c2 = (unsigned char *) src;
	i = 0;
	if (c1 > c2)
	{
		while (n-- > 0)
			c1[n] = c2[n];
	}
	else
	{
		while (i < n)
		{
			c1[i] = c2[i];
			i++;
		}
	}
	return (dest);
}
