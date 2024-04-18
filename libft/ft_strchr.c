/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:23:57 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:21 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	sr;

	sr = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == sr)
			break ;
		i++;
	}
	if (s[i] == '\0' && sr != '\0')
		return (0);
	return ((char *)s + i);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char s[21] = "qwerasdfqwerasdfqwer";
	char s2[21] = "qwerasdfqwerasdfqwer";
	char c = 'p';

	printf("%s\n", strchr(s,c));
	printf("%s\n", ft_strchr(s2,c));
}*/
