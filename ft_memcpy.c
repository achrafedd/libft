/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:44:33 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/24 23:57:31 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	c1 = (unsigned char *) dest;
	c2 = (unsigned char *) src;
	while (i < n)
	{
		c1[i] = c2[i];
		i++;
	}
	return (dest);
}
