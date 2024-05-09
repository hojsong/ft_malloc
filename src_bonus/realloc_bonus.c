/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:01:47 by hojsong           #+#    #+#             */
/*   Updated: 2024/05/09 18:20:34 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc_bonus.h"

void	*o_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*s;

	c = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = -1;
	if (dst == src)
		return (dst);
	else if (dst > src)
	{
		while (len--)
			c[len] = s[len];
	}
	else
	{
		while (++i < len)
			c[i] = s[i];
	}
	return (dst);
}

void	*realloc(void *ptr, size_t size)
{
	void 	*result;
	size_t	osiz;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(size));
	osiz = get_size(ptr);
	if (size <= osiz)
	 	return (ptr);
	result = malloc(size);
	if (result == NULL)
		return (NULL);
	o_memmove(result, ptr, osiz);
	free(ptr);
	return (result);
}
