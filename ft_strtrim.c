/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 08:52:08 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/22 12:08:14 by aeddiba          ###   ########.fr       */
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

static char	*creat_str(char const *str, int start, int end)
{
	char	*res;
	int		i;

	res = (char *) malloc(end - start + 1);
	i = 0;
	while (i < (end - start))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
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
		res = (char *) malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	start = 0;
	end = ft_strlen(s1);
	while (start < end && check_set(s1[start], set))
		start++;
	while (end > start && check_set(s1[end -1], set))
		end--;
	res = creat_str(&s1[start], start, end);
	return (res);
}
