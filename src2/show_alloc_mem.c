/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:51:32 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/22 09:55:39 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc2.h"

t_sta	*g_all;

static void	put_hex_num(int fd, unsigned long long ptr, int idx)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (idx == 7)
		put_str_fd(fd, "0x");
	else
		put_hex_num(fd, ptr / 16, idx + 1);
	write(fd, &str[ptr % 16], 1);
}

static void	print_of_easy(int fd, t_st *src, size_t idx, size_t size)
{
	put_hex_num(fd, (unsigned long long)src->ptr + \
		(unsigned long long)idx, 0);
	put_str_fd(fd, " - ");
	put_hex_num(fd, (unsigned long long)src->ptr + \
		(unsigned long long)idx + (unsigned long long)size, 0);
	put_str_fd(fd, " : ");
	put_num_fd(fd, size);
	put_str_fd(fd, " bytes\n");
}

static size_t	easy_print(int fd, t_st *src)
{
	size_t	idx;
	size_t	result;

	result = 0;
	idx = 0;
	while (idx * 16 < src->size)
	{
		if (src->si[idx])
			print_of_easy(fd, src, idx * 16, src->si[idx]);
		result += src->si[idx];
		idx++;
	}
	return (result);
}

static size_t	put_ptr_fd(int fd, t_st *ptr)
{
	t_st	*src;
	t_st	*dest;
	size_t	result;

	result = 0;
	src = ptr;
	put_hex_num(fd, (unsigned long long)src->ptr, 0);
	put_str_fd(fd, "\n");
	while (src)
	{
		if(src->si)
			result += easy_print(fd, src);
		else
		{
			print_of_easy(fd, src, 0, src->size);
			result += src->size;
		}
		dest = src;
		src = dest->next;
	}
	return (result);
}

void    show_alloc_mem(void)
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