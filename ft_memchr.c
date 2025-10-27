/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:42:40 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/26 18:41:27 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*bytes;
	unsigned char	target;
	size_t			i;

	i = 0;
	bytes = (unsigned char *) s;
	target = (unsigned char) c;
	while (i < n)
	{
		if (bytes[i] == target)
			return ((void *)&bytes[i]);
		i++;
	}
	return (NULL);
}
