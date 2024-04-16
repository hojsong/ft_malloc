/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tst_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:00:02 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/13 04:19:48 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc.h"

t_sta	*g_all;
int		g_blakcs_size;
int		g_blakc_one;

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

void	*find_mem(t_st *src, size_t size)
{
	t_st	*dest;
	t_st	*m;
	size_t	len;
	int		i;
	int		x;

	len = 0;
	dest = src;
	while (dest)
	{
		m = dest;
		if (m->size + size <= m->max_size)
		{
			i = -1;
			len = m->size;
			x = m->si[m->size - 1] + 1;
			while ((size_t)++i < size)
				m->si[i + m->size] = x;	
			m->size += (resize(size) * g_blakc_one);
			return (&m->ptr[len]);
		}
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
	while (i < src->max_size)
	{
		if (i < size)
			src->si[i] = 0;
		else
			src->si[i] = -1;
		i++;
	}
}
