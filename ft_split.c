/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:49:10 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/19 11:00:39 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
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

	while (s[len] != c)
		len++;
	i = 0;
	res = (char *) malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	while (s[i] != c)
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

	res = (char **) malloc(sizeof(char *) * words + 1);
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

	if (!s || !c)
		return (NULL);
	words = count_words(s, c);
	res = append(s, c, words);
	return (res);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype of your function
char	**ft_split(char const *s, char c);

void print_result(char **arr)
{
	if (!arr)
	{
		printf("NULL\n");
		return;
	}
	for (int i = 0; arr[i]; i++)
	{
		printf("\"%s\"", arr[i]);
		if (arr[i + 1])
			printf(", ");
	}
	printf("\n");
}

int compare_split(char **result, const char **expected)
{
	if (!result && !expected)
		return 1;
	if (!result || !expected)
		return 0;

	for (int i = 0; expected[i] || result[i]; i++)
	{
		if (!expected[i] || !result[i])
			return 0;
		if (strcmp(result[i], expected[i]) != 0)
			return 0;
	}
	return 1;
}

void free_split(char **arr)
{
	if (!arr) return;
	for (int i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}

void run_test(const char *s, char c, const char **expected, const char *desc)
{
	char **result = ft_split(s, c);
	int ok = compare_split(result, expected);

	if (ok)
	{
		printf("✅ %-25s | s=\"%s\" c='%c' | got: ", desc, s ? s : "NULL", c);
		print_result(result);
	}
	else
	{
		printf("❌ %-25s | s=\"%s\" c='%c' | expected: ", desc, s ? s : "NULL", c);
		if (expected)
		{
			for (int i = 0; expected[i]; i++)
			{
				printf("\"%s\"", expected[i]);
				if (expected[i + 1]) printf(", ");
			}
		}
		else
		{
			printf("NULL");
		}
		printf(" | got: ");
		print_result(result);
	}

	free_split(result);
}

int main(void)
{
	const char *exp1[] = {"Hello", "World", NULL};
	const char *exp2[] = {"Hello", "split", "function", NULL};
	const char *exp3[] = {"Hello", NULL};
	const char *exp4[] = {NULL};
	const char *exp5[] = {"one", "two", "three", NULL};
	const char *exp6[] = {"multiple", "delimiters", NULL};

	// Normal cases
	run_test("Hello World", ' ', exp1, "Basic split");
	run_test("Hello-split-function", '-', exp2, "Split with dash");
	run_test(" one two three ", ' ', exp5, "Trim spaces");

	// Edge cases
	run_test("", ' ', exp4, "Empty string");
	run_test(" ", ' ', exp4, "String with only delimiter");
	run_test(NULL, ' ', NULL, "NULL string");
	run_test("Hello", 'x', exp3, "No delimiter found");

	// Multiple delimiters
	run_test("multiple,,,delimiters", ',', exp6, "Extra delimiters");

	return 0;
}
