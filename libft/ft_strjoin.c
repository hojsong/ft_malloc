/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:50:54 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:27 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_sslen(char const *c)
{
	unsigned int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;

	len1 = 0;
	len2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	len1 = ft_sslen(s1);
	len2 = ft_sslen(s2);
	i = 0;
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
		return (0);
	while (i < len1 + len2)
	{
		if (i < len1)
			result[i] = (char)s1[i];
		else
			result[i] = (char)s2[i - len1];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
	char s1[10] = "abcdefghi";
	char s2[10] = "123456789";
	char *c;

	c = ft_strjoin(s1,s2);
	printf("%s\n",c);
}*/
