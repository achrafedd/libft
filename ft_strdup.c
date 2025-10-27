/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:40:15 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/26 22:01:07 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len;

	len = ft_strlen(s);
	res = (char *) ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s, len);
	return (res);
}
