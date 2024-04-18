/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:06:51 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:43 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ilen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_ilen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (const char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char s[21] = "asdfqwerasdfqwerasdf";
	char s2[21] = "asdfqwerasdfqwerasdf";
	char c = 's';

	printf("%s\n",strrchr(s,c));
	printf("%s\n",ft_strrchr(s2,c));
}*/
