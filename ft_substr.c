/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1338.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:09:21 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/22 09:54:47 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	count_len(char const *str, unsigned int start)
{
	size_t	i;

	i = 0;
	while (str[i + start])
	{
		i++;
	}
	return (i);
}

size_t	count_total(char const *s, unsigned int start, size_t len)
{
	size_t	total;
	size_t	slen;

	slen = ft_strlen(s);
	total = len + 1;
	if (len - start > slen)
		total = slen - start + 1;
	if (len >= count_len(s, start))
		total = count_len(s, start) + 1;
	return (total);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start || !(*s) || !(*s + start))
	{
		res = malloc(1);
		*res = '\0';
		return (res);
	}
	res = (char *) malloc(sizeof(char) * count_total(s, start, len));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*(s + start + i) != '\0' && i < len)
	{
		res[i] = *(s + start + i);
		i++;
	}
	res[i] = '\0';
	return (res);
}
