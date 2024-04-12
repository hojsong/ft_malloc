/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:56:48 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/13 01:29:25 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc.h"

t_sta	*g_all;

size_t	si_replace(t_st *src, size_t idx)
{
	size_t	size;

	size = 1;
	if (!src->si)
	{
		src->max_size = 1;
		return (size);
	}
	while (src->si[idx + size] == src->si[idx] && size < src->max_size)
	{
		src->si[idx + size] = -1;
		size++;
	}
	src->si[idx] = -1;
	size = 0;
	while (size < src->max_size)
	{
		if (src->si[size] == -1)
			size++;
		else
			break ;
	}
	return (size);
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
			munmap(src->si, sizeof(int) * src->max_size);
			munmap(src, sizeof(t_st));
			src = NULL;
		}
	}
}

t_st	*newlst(size_t size)
{
	t_st	*result;

	result = mmap(0, sizeof(t_st), PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (result == MAP_FAILED)
		return (fail_map(result));
	result->max_size = ((size / 8192) + 1) * 8192;
	result->size = size;
	result->ptr = mmap(0, size, PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (result->ptr == MAP_FAILED)
		return (fail_map(result));
	result->si = mmap(0, sizeof(int) * result->max_size, \
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (result->si == MAP_FAILED)
		return (fail_map(result));
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
		src->next = newlst(size);
		dest = src;
		src = dest->next;
	}
	else
	{
		src = newlst(size);
		g_all->large = src;
	}
	return (src);
}
