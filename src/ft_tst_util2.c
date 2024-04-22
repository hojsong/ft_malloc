/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tst_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:00:02 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/22 07:07:49 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc.h"

t_sta	*g_all;
size_t	g_blakcs_size;
size_t	g_blakc_one;
size_t	g_t_st_size;

t_st	*t_stinit(t_st *src, size_t size)
{
	if (src == NULL)
	{
		if (size < TINY_SIZE)
		{
			g_all->tiny = newlst(size);
			return (g_all->tiny);
		}
		else if (size < SMALL_SIZE)
		{
			g_all->small = newlst(size);
			return (g_all->small);
		}
		else if (size > SMALL_SIZE)
			return (large(size));
	}
	return (NULL);
}

t_st	*size_of_return(size_t size)
{
	if (size < TINY_SIZE)
		return (g_all->tiny);
	else if (size < SMALL_SIZE)
		return (g_all->small);
	else if (size > SMALL_SIZE)
		return (g_all->large);
	return (NULL);
}

int	find_si(t_st *src, size_t size)
{
	size_t	idx;
	size_t	dust;
	size_t	x;

	idx = 0;
	while(src->si && idx * 16 < src->max_size && src->si[idx])
	{
		dust = src->si[idx] / 16;
		if (src->si[idx] % 16)
			dust++;
		idx += dust;
		if (src->si[idx] != 0)
			continue;
		x = 0;
		while ((idx + x) * 16 < src->max_size && src->si[idx + x] == 0)
			x++;
		if (x * 16 >= size)
		{
			src->si[idx] = size;
			return (idx * 16);
		}
		idx++;
	}
	return (-1);
}

void	*find_mem(t_st *src, size_t size)
{
	t_st	*dest;
	t_st	*m;
	int		x;

	dest = src;
	while (dest)
	{
		m = dest;
		x = find_si(m, size);
		if (x != -1)
			return (&m->ptr[x]);
		dest = m->next;
	}
	m->next = newlst(size);
	return (m->next->ptr);
}

int	findof_ptr_free(void *ptr, t_st *src, char *str)
{
	t_st	*dest;
	t_st	*src2;

	dest = NULL;
	src2 = src;
	while (src2)
	{
		if (ptr == src2->ptr || ptr == src || \
		(ptr >= src2->ptr && ptr < src2->ptr + src2->max_size))
		{
			m_ft_replace(ptr, src2, dest, str);
			return (1);
		}
		dest = src2;
		src2 = dest->next;
	}
	return (0);
}

void	lst_si_init(t_st *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i * 16 < src->max_size)
	{
		if (i < size)
			src->si[i] = 0;
		i++;
	}
	src->si[0] = size;
}
