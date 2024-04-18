/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:37:53 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:33:52 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)s;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}
/*
#include <strings.h>
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	char c[18] = "asd fdsa asd fdsa";
	char c2[18] = "asd fdsa asd fdsa";
	int i;

	printf("c : %s\n",c);
	printf("c2 : %s\n",c2);
	bzero(c, 10);
	ft_bzero(c2, 10);
	for(i = 0; i<18; i++)
	{
		printf("%c",c[i]);
	}
	printf("\n");
	for(i = 0; i<18; i++)
	{
		printf("%c",c2[i]);
	}
}*/
