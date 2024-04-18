/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:06:16 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:41 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *src, size_t l)
{
	size_t	i;
	size_t	i2;

	i = 0;
	if (*src == '\0')
		return ((char *)str);
	else if (*str == '\0')
		return (0);
	if (ft_strlen(str) < ft_strlen(src))
		return (0);
	while (i < l && str[i])
	{
		i2 = 0;
		while (str[i + i2] == src[i2] && str[i + i2] && i + i2 < l)
		{
			i2++;
			if (src[i2] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char s1[21] = "asdfqwerasdfqwerasdf";
	char c1[5] = "qwer";

	printf("%s\n",strnstr(s1,c1,9));
	printf("%s\n",ft_strnstr(s1,c1,9));
}*/
