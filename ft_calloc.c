/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddiba <aeddiba@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:24:37 by aeddiba           #+#    #+#             */
/*   Updated: 2025/10/24 20:50:54 by aeddiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory;

	if (!nmemb || !size)
	{
		memory = (char *) malloc(1);
		memory[0] = 0;
		return ((void *)memory);
	}
	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);
	ft_bzero((void *) memory, size * nmemb);
	return ((void *) memory);
}
