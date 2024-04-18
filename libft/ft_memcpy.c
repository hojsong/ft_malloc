/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:15:35 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:00 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char dest[15] = "asdfdsadfaasds";
	char dest2[15] = "asdfdsadfaasds";
	char src[9] = "i am song";

	memcpy(dest, src, sizeof(src));
	ft_memcpy(dest2, src, sizeof(src));
	printf("%s\n",dest);
	printf("%s\n",dest2);
}*/
