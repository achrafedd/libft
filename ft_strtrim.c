/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 08:52:08 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/27 16:22:04 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
	{
		res = (char *) ft_calloc(1, sizeof(char));
		return (res);
	}
	start = 0;
	end = ft_strlen(s1);
	while (start < end && check_set(s1[start], set))
		start++;
	while (end > start && check_set(s1[end -1], set))
		end--;
	res = (char *) ft_calloc(end - start + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_memmove(res, &s1[start], end - start);
	return (res);
}
