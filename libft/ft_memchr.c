/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:45:02 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:34:54 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	se;
	size_t			i;

	se = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == se)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char s1[17] = "asdfqwerasdfqwer";
	char s2[17] = "asdfqwerasdfqwer";
	char c = 'f';

	printf("%s\n",memchr(s1,c,sizeof(s1)));
	printf("%s\n",ft_memchr(s2,c,sizeof(s2)));
}*/
