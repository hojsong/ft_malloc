/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:57:09 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:34:57 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char s1[21] = "qwerasdfqwerasdfqwer";
	char s2[21] = "qwerasdfqwerasdfqwer";
	char s3[21] = "qwerasdfqwerasdfqwef";

	printf("memcmp : %d\n",memcmp(s1,s3,sizeof(s1)));
	printf("ft_memcmp : %d\n",ft_memcmp(s2,s3,sizeof(s2)));
}*/
