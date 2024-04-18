/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:59:05 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:33:55 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc((size) * (count));
	if (str == NULL)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	int arr1[5];
	int *arr2;
	int *arr3;
	int i;

	for(i=0;i<5;i++)
		arr1[i] = i + 1;
	arr2 = (int *)calloc(5,sizeof(int));
	arr3 = ft_calloc(5,sizeof(int));

	for(i = 0; i<5;i++)
	{
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
	}
	for(i=0; i<5; i++)
		printf("%d",arr2[i]);
	printf("\n");
	for(i=0; i<5; i++)
		printf("%d",arr3[i]);
	printf("\n");
}*/
