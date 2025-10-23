/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:49:10 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/22 18:51:23 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i] == c)
		i++;
	if (!s[i])
		return (0);
	count = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count + 1);
}

static char	*create_str(char const *s, char c)
{
	char	*res;
	int		i;
	int		len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	i = 0;
	res = (char *) malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static char	**append(char const *s, char c, int words)
{
	char	**res;
	int		i;

	res = (char **) malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		res[i] = create_str(s, c);
		if (res[i] == NULL)
		{
			free_all(res);
			return (NULL);
		}
		s += ft_strlen(res[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = append(s, c, words);
	return (res);
}
