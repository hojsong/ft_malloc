/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:40:04 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/22 10:40:22 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc2.h"

t_sta	*g_all;

void	*realloc(void *ptr, size_t size)
{
	unsigned char	*result;
	unsigned char	*str;
	size_t	idx;

	result = malloc(size);
	if (ptr != NULL)
	{
		str = (unsigned char *)ptr;
		idx = 0;
		while (idx < size && str[idx])
		{
			result[idx] = str[idx];
			idx++;
		}
		free(ptr);
	}
	return (result);
}
