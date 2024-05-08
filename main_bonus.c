/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:56:56 by hojsong           #+#    #+#             */
/*   Updated: 2024/05/08 11:17:39 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
// #include "header/malloc3.h"
#include "header/malloc_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	all_free(char **str)
{
	size_t	idx;

	idx = 0;
	while (idx < 1000)
	{
		free(str[idx]);
		str[idx] = NULL;
		idx++;
	}
	free(str);
}

int	main(void)
{
	char	*str;
	char	**str2;
	int		i;

	str = ft_strdup("Hellow~~~~\n");
	ft_putstr_fd(str, 1);
	// str = strdup("Hellow~~~~\n");
	// printf("%s", str);
	str2 = malloc(sizeof(char *) * 1001);
	show_alloc_mem();
	printf("------------------------------------------\n");
	i = 0;
	while (i < 1000)
	{
		// printf("i : %d\n", i);
		str2[i] = malloc(sizeof(char) * ((i + 1)) * 10);
		i++;
	}
	str2[1000] = NULL;
	show_alloc_mem();
	printf("------------------------------------------\n");
	free(str);
	all_free(str2);
	show_alloc_mem_ex();
	printf("------------------------------------------\n");
	return (0);
}
