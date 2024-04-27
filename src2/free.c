/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:27:24 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/28 00:32:04 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc2.h"

t_sta	*g_all;

static size_t	si_replace(t_st *src, size_t idx)
{
	size_t	x;
	
	if (src->si == NULL)
		return (src->size);
	x = 0;
	src->si[idx / 16] = 0;
	while (x * 16 < src->size && src->si[x] == 0)
    {
        x++;
    }
	return ((x * 16));
}

static int	si_replace_end(t_st *src, t_st *dest, char *str)
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

static void	m_ft_replace(void *ptr, t_st *src, t_st *dest, char *str)
{
	size_t	size;
	size_t	idx;

    idx = 0;
	if (ptr == src)
        idx = src->size;
	else
	{
		idx = ptr - src->ptr;
		idx = si_replace(src, idx);
	}
	if (idx >= src->size)
	{
		if (si_replace_end(src, dest, str) == 1)
			dest->next = src->next;
		size = resize(src->size + sizeof(t_st), getpagesize() * 2);
		munmap(src, size);
		src = NULL;
	}
}

static int findof_ptr_free(void *ptr, t_st *src, char *str)
{
	t_st	*dest;
	t_st	*src2;

	dest = NULL;
	src2 = src;
	while (src2)
	{
		if (ptr == src2->ptr || ptr == src || \
		(ptr >= src2->ptr && ptr <= src2->ptr + src2->size))
		{
			m_ft_replace(ptr, src2, dest, str);
            if (g_all->tiny || g_all->small || g_all->large)
			    return (1);
            munmap(g_all, getpagesize() * 2);
            g_all = NULL;
            return (1);
		}
		dest = src2;
		src2 = dest->next;
	}
	return (0);
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
