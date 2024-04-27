/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:47:17 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/28 00:46:22 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc2.h"

t_sta	*g_all;

static void	*fail_map(t_st *src, size_t size)
{
	put_str_fd(2, "Mmap Error\n");
	if (src)
		munmap(src, size);
	return (NULL);
}

static t_st	*newLarge(size_t size)
{
	void	*ptr;
	t_st	*result;
	size_t	m_size;
	size_t	x;

	m_size = resize(sizeof(t_st) + size, getpagesize() * 2);
	ptr = mmap(0, m_size, PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (ptr == MAP_FAILED)
		return (fail_map(ptr, m_size));
	x = resize(sizeof(t_st), 16);
	result = &ptr[0];
	result->size = size;
	result->ptr = &ptr[x];
	result->si = NULL;
	result->next = NULL;
	return (result);
}

static void	lst_idx_init(t_st *src, size_t size)
{
	size_t	i;

	i = 0;
	while(i < src->size / 16)
	{
		src->si[i] = 0;
		i++;
	}
	src->si[0] = size;
}

static t_st	*newlst(size_t size)
{
	void	*ptr;
	t_st	*result;
	size_t	m_size;
	size_t	x;

	m_size = resize(sizeof(t_st) + size, getpagesize() * 2);
	ptr = mmap(0, m_size, PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (ptr == MAP_FAILED)
		return (fail_map(ptr, m_size));
	x = resize(sizeof(t_st), 16);
	result = &ptr[0];
	result->size = (m_size - x) / 5 * 4;
	result->ptr = &ptr[x];
	result->si = &ptr[x + result->size];
	lst_idx_init(result, size);
	result->next = NULL;
	return (result);
}

static t_st	*large(size_t size)
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

static t_st	*t_stinit(size_t size)
{
	if (size <= TINY_SIZE)
	{
		g_all->tiny = newlst(size);
		return (g_all->tiny);
	}
	else if (size > TINY_SIZE && size <= SMALL_SIZE)
	{
		g_all->small = newlst(size);
		return (g_all->small);
	}
	else
		return (large(size));
}

static int	find_si(t_st *src, size_t size)
{
	size_t	dust;
	size_t	idx;
	size_t	x;

	idx = 0;
	while(src->si && idx * 16 < src->size)
	{
		dust = resize(src->si[idx], 16) / 16;
		idx += dust;
		if (idx * 16 + size >= src->size)
			break;
		if (src->si[idx] != 0)
			continue;
		x = 0;
		while (x * 16 < size && (idx + x) * 16 < src->size && src->si[idx + x] == 0)
			x++;
		if (x * 16 >= size)
		{
			src->si[idx] = size;
			return (idx * 16);
		}
		idx += x;
	}
	return (-1);
}

static void	*find_mem(t_st *src, size_t size)
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
	if (m->next == NULL)
		return (NULL);
	return (m->next->ptr);
}

void	*malloc(size_t size)
{
	void	*ptr;
	t_st	*m;
	size_t	size2;

	if (size <= 0)
		return (NULL);
	if (g_all == NULL)
	{
		size2 = sizeof(t_sta);
		g_all = mmap(0, size2, PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	}
	m = size_of_return(size);
	if (m == NULL)
	{
		if (size <= TINY_SIZE)
			m = t_stinit(size);
		else if (size > TINY_SIZE && size <= SMALL_SIZE)
			m = t_stinit(size);
		else
			m = t_stinit(size);
		if (m)
			return (m->ptr);
		else
			return (NULL);
	}
	ptr = find_mem(m, size);
	return (ptr);
}

// int main()
// {
// 	char	*str;
// 	char	*str2;
// 	char	*str3;
// 	size_t	idx;
	
// 	idx = 0;
// 	str = malloc(100);
// 	str2 = malloc(100);

// 	// while (idx < g_all->tiny->size / 16)
// 	// {
// 	// 	if (g_all->tiny->si[idx])
// 	// 		printf("%zu : %d\n", idx, g_all->tiny->si[idx]);
// 	// 	idx ++;
// 	// }
// 	// printf("size : %zu\n",sizeof(t_st));
// 	printf("tiny : %p\n", (void *)g_all->tiny);
// 	printf("ptr  : %p\n", (void *)g_all->tiny->ptr);
// 	printf("si   : %p\n", (void *)g_all->tiny->si);
// 	printf("str  : %p\n", (void *)str);
// 	printf("str2 : %p\n", (void *)str2);
// 	free(str);
// 	str3 = malloc(100);
// 	printf("str3 : %p\n", (void *)str3);
// 	printf("tiny : %p\n", (void *)g_all->tiny);
// 	printf("str  : %p\n", (void *)str);
// 	show_alloc_mem();
// 	free(str2);
// 	printf("tiny : %p\n", (void *)g_all->tiny);
// 	printf("str2  : %p\n", (void *)str2);
// 	free(str3);
// 	show_alloc_mem();
// }