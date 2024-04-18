/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:37:28 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:47 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_l;
	char	*str;

	if (s == NULL )
		return (0);
	if (len <= 0 || (unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	s_l = ft_strlen(s + start);
	if (s_l < len)
		len = s_l;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char *a;

	a = ft_substr(a, 32, 95);
	printf("%s\n",a); 
}*/
