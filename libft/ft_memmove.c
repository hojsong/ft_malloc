/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:44:47 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/13 19:19:24 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
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
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char dest[15] = "fdsa";
	char src[11] = "asdjkbasjk";

	ft_memmove(dest,src,sizeof(src));
	printf("%s\n",dest);
}*/
