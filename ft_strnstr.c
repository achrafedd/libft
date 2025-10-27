/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:08:16 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/27 15:38:34 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	llen;

	i = 0;
	if (!(*little))
		return ((char *) big);
	llen = ft_strlen(little);
	while (big[i] && i + llen <= len)
	{
		if (!ft_strncmp(&big[i], little, llen))
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
