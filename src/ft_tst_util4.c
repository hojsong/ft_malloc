/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tst_util4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:06:12 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/22 06:52:25 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc.h"

t_sta	*g_all;
size_t	g_blakcs_size;
size_t	g_blakc_one;
size_t	g_t_st_size;

void    init(void)
{
	if (getpagesize() == 8192)
   		g_blakcs_size = getpagesize();
	else
		g_blakcs_size = 8192;
    g_blakc_one = sizeof(size_t) * 2;
	g_t_st_size = sizeof(t_st);
}

t_st    *newLarge(size_t size)
{
    t_st	*result;

	result = mmap(0, sizeof(t_st), PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (result == MAP_FAILED)
		return (fail_map(result));
	result->max_size = ((size / g_blakcs_size) + 1) * g_blakcs_size;
	result->size = size;
	result->ptr = mmap(0, result->max_size, PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (result->ptr == MAP_FAILED)
		return (fail_map(result));
    result->si = NULL;
	result->next = NULL;
	return (result);
}