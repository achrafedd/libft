/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 08:52:08 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/18 10:44:02 by aeddiba          ###   ########.fr       */
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

	res = (char *) malloc(sizeof(char) * (end - start) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start) + 1)
	{
		res[i] = str[start + i];
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
	end = ft_strlen(s1) - 1;
	while (check_set(s1[start], set) && s1[start])
		start++;
	while (check_set(s1[end], set) && end > start)
		end--;
	res = creat_str(s1, start, end);
	return (res);
}
