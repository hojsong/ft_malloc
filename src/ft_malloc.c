/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:06:12 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/17 16:48:50 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc.h"

t_sta	*g_all;
size_t	g_blakcs_size;
size_t	g_blakc_one;

void	*malloc(size_t size)
{
	t_st	*m;
	size_t	size2;

	init();
	if (size <= 0)
		return (NULL);
	if (g_all == NULL)
	{
		size2 = sizeof(t_sta);
		if (size2 < (size_t)g_blakcs_size)
			size2 = (size_t)g_blakcs_size;
		g_all = mmap(0, size2, PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	}
	if (size < TINY_SIZE)
		m = t_stinit(g_all->tiny, size);
	else if (size < SMALL_SIZE)
		m = t_stinit(g_all->small, size);
	else
		m = t_stinit(NULL, size);
	if (m)
		return (m->ptr);
	m = size_of_return(size);
	return (find_mem(m, size));
}

void	free(void *ptr)
{
	t_st	*src;

	init();
	src = g_all->tiny;
	if (findof_ptr_free(ptr, src, "tiny"))
		return ;
	src = g_all->small;
	if (findof_ptr_free(ptr, src, "small"))
		return ;
	src = g_all->large;
	if (findof_ptr_free(ptr, src, "large"))
		return ;
}

void	*realloc(void *ptr, size_t size)
{
	unsigned char	*result;
	unsigned char	*str;
	size_t	idx;

	init();
	str = (unsigned char *)ptr;
	result = malloc(size);
	if (str != NULL)
	{
		idx = 0;
		while (idx < size)
		{
			result[idx] = str[idx];
			idx++;
		}
	}
	free(ptr);
	return (result);
}

void	show_alloc_mem(void)
{
	size_t	total;

	total = 0;
	put_str_fd(1, "TINY  : ");
	if (g_all && g_all->tiny)
		total += put_ptr_fd(1, g_all->tiny);
	else
		put_str_fd(1, "NULL\n");
	put_str_fd(1, "Small : ");
	if (g_all && g_all->small)
		total += put_ptr_fd(1, g_all->small);
	else
		put_str_fd(1, "NULL\n");
	put_str_fd(1, "LARGE : ");
	if (g_all && g_all->large)
		total += put_ptr_fd(1, g_all->large);
	else
		put_str_fd(1, "NULL\n");
	put_str_fd(1, "Total : ");
	put_num_fd(1, total);
	put_str_fd(1, "\n");
}
