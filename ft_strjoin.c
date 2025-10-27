/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:52:37 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/27 15:37:47 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		total_size;
	int		s1len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	total_size = s1len + ft_strlen(s2);
	res = (char *) malloc(sizeof(char) * total_size + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1, s1len);
	ft_memcpy(res + s1len, s2, total_size - s1len + 1);
	return (res);
}
