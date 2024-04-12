/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tst_util3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:39:07 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/13 00:59:52 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc.h"

t_sta	*g_all;

void	*fail_map(t_st *src)
{
	put_str_fd(2, "Mmap Error\n");
	if (src)
	{
		if (src->ptr)
			munmap(src->ptr, src->max_size);
		if (src->si)
			munmap(src->si, sizeof(int) * src->max_size);
		munmap(src, sizeof(t_st));
	}
	return (NULL);
}

void	print_of_easy(int fd, t_st *src, size_t idx, size_t size)
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

void	easy_print(int fd, t_st *src)
{
	size_t	idx;
	size_t	size;

	idx = 0;
	while (idx < src->max_size)
	{
		size = 1;
		while (src->si[idx] == -1 && idx < src->max_size)
			idx++;
		while (src->si[idx + size - 1] == src->si[idx + size] && \
			idx + size < src->size)
			size++;
		if (src->si[idx] != -1)
			print_of_easy(fd, src, idx, size);
		if (idx + size >= src->size)
			break ;
		idx += size;
	}
}

void	put_ptr_fd(int fd, t_st *ptr)
{
	t_st	*src;
	t_st	*dest;

	src = ptr;
	put_hex_num(fd, (unsigned long long)src->ptr, 0);
	put_str_fd(fd, "\n");
	while (src)
	{
		easy_print(fd, src);
		dest = src;
		src = dest->next;
	}
}
