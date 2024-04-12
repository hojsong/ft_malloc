/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:06:12 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/13 01:23:55 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc.h"

t_sta	*g_all;

void	*malloc(size_t size)
{
	t_st	*m;

	if (size <= 0)
		return (NULL);
	if (g_all == NULL)
		g_all = mmap(0, sizeof(t_sta), PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (size <= 1024)
		m = t_stinit(g_all->tiny, size);
	else if (size <= 4096)
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
	free(ptr);
	ptr = malloc(size);
	return (ptr);
}

void	show_alloc_mem(void)
{
	put_str_fd(1, "TINY : ");
	if (g_all && g_all->tiny)
		put_ptr_fd(1, g_all->tiny);
	else
		put_str_fd(1, "NULL\n");
	put_str_fd(1, "Small : ");
	if (g_all && g_all->small)
		put_ptr_fd(1, g_all->small);
	else
		put_str_fd(1, "NULL\n");
	put_str_fd(1, "LARGE : ");
	if (g_all && g_all->large)
		put_ptr_fd(1, g_all->large);
	else
		put_str_fd(1, "NULL\n");
}
