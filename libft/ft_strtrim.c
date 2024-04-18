/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:14:43 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:45 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	sta;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 != NULL && set != NULL)
	{
		sta = 0;
		end = ft_strlen((char *)s1);
		while (sta < end && ft_strchr(set, s1[sta]))
			sta++;
		while (end > 0 && ft_strchr(set, s1[end - 1]) && sta < end)
			end--;
		str = (char *)malloc(sizeof(char) * (end - sta + 1));
		if (str == NULL)
			return (0);
		ft_strlcpy(str, &s1[sta], end - sta + 1);
	}
	return (str);
}
/*
int main()
{
	char s1[200] = "f0asdf0asdqwf0asdf0r0";
	char s2[3] = "f0";
	char *str;

	str = ft_strtrim(s1,s2);
	printf("%s\n",str);
}*/
