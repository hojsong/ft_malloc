/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:58:53 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:30 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_size;
	size_t	s_size;
	size_t	index;

	s_size = ft_strlen((char *)src);
	if (dest == NULL && size == 0)
		return (s_size);
	d_size = ft_strlen(dest);
	if (d_size > size)
		return (s_size + size);
	index = 0;
	while ((index + d_size + 1) < size && src[index] != '\0')
	{
		dest[d_size + index] = src[index];
		index++;
	}
	dest[d_size + index] = '\0';
	return (d_size + s_size);
}
