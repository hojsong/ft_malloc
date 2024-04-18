/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tst_util3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:39:07 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/18 16:22:41 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc.h"

t_sta	*g_all;
size_t	g_blakcs_size;
size_t	g_blakc_one;

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

size_t	easy_print(int fd, t_st *src)
{
	size_t	idx;
	size_t	result;

	result = 0;
	idx = 0;
	while (idx * 16 < src->max_size)
	{
		if (src->si[idx])
			print_of_easy(fd, src, idx * 16, src->si[idx]);
		result += src->si[idx];
		idx++;
	}
	return (result);
}

size_t	put_ptr_fd(int fd, t_st *ptr)
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

size_t	resize(size_t size)
{
	size_t	result;

	result = size / g_blakc_one;
	if (size % g_blakc_one)
		result++;
	return result;
}