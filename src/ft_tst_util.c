/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:56:48 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/22 07:03:40 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc.h"

t_sta	*g_all;
size_t	g_blakcs_size;
size_t	g_blakc_one;
size_t	g_t_st_size;

size_t	si_replace(t_st *src, size_t idx)
{
	size_t	x;
	
	if (src->si == NULL)
		return (src->max_size);
	x = 0;
	src->si[idx / 16] = 0;
	while (x * 16 < src->max_size && src->si[x] == 0)
		x++;
	return (x * 16);
}

int	si_replace_end(t_st *src, t_st *dest, char *str)
{
	if (!dest && src->next)
	{
		if (!m_ft_strcmp(str, "tiny"))
			g_all->tiny = src->next;
		else if (!m_ft_strcmp(str, "small"))
			g_all->small = src->next;
		else if (!m_ft_strcmp(str, "large"))
			g_all->large = src->next;
		return (0);
	}
	else if (!dest && !src->next)
	{
		if (!m_ft_strcmp(str, "tiny"))
			g_all->tiny = NULL;
		else if (!m_ft_strcmp(str, "small"))
			g_all->small = NULL;
		else if (!m_ft_strcmp(str, "large"))
			g_all->large = NULL;
		return (0);
	}
	return (1);
}

void	m_ft_replace(void *ptr, t_st *src, t_st *dest, char *str)
{
	size_t	size;
	size_t	idx;

	if (ptr == src)
		idx = 0;
	else
		idx = ptr - src->ptr;
	idx = si_replace(src, idx);
	if (idx == src->max_size)
	{
		if (si_replace_end(src, dest, str) == 1)
		{
			dest->next = src->next;
			munmap(src->ptr, src->max_size);
			if(src->si)
				munmap(src->si, sizeof(int) * src->max_size / 16);
			size = sizeof(t_st);
			if (size < (size_t)g_blakcs_size)
				size = (size_t)g_blakcs_size;
			munmap(src, size);
			src = NULL;
		}
	}
}

t_st	*newlst(size_t size)
{
	t_st	*result;
	size_t	m_size;

	result = mmap(g_all, sizeof(t_st), PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (result == MAP_FAILED)
		return (fail_map(result));
	if (size % g_blakcs_size)
		m_size = ((size / g_blakcs_size) + 1) * g_blakcs_size;
	else
		m_size = ((size / g_blakcs_size)) * g_blakcs_size;
	result->size = (resize(size));
	result->max_size = m_size / 5 * 4;
	result->ptr = mmap(0, m_size, PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (result->ptr == MAP_FAILED)
		return (fail_map(result));
	result->si = (int *)(&result->ptr[m_size / 5 * 4]);
	lst_si_init(result, size);
	result->next = NULL;
	return (result);
}

t_st	*large(size_t size)
{
	t_st	*src;
	t_st	*dest;

	src = g_all->large;
	if (src)
	{
		while (src->next)
		{
			dest = src;
			src = dest->next;
		}
		src->next = newLarge(size);
		dest = src;
		src = dest->next;
	}
	else
	{
		src = newLarge(size);
		g_all->large = src;
	}
	return (src);
}
