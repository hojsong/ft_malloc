/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 04:50:39 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:32 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s_s;

	s_s = 0;
	while (src[s_s])
		s_s++;
	if (size == 0)
		return (s_s);
	i = 0;
	while (i + 1 < size && i < s_s)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (s_s);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	//char dest1[20] = "fdsafdsafdsafdsafds";
	//char dest2[20] = "dsadsdsadasdasdasaa";
	char dest1[20] = "";
	char dest2[20] = "";
	char src[20] = "asdfqwerasrasd";

	printf ("%lu : %s\n",strlcpy(dest1,src,20),dest1);
	printf ("%lu : %s\n",ft_strlcpy(dest2,src,20),dest2);
}*/
