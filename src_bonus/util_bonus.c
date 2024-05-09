/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:01:31 by hojsong           #+#    #+#             */
/*   Updated: 2024/05/09 18:29:30 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/malloc_bonus.h"

void	init_lcok(void)
{
	if (g_stack == NULL)
		pthread_mutex_init(&g_gardner, NULL);
	pthread_mutex_lock(&g_gardner);
}

size_t return_size(t_st *x, size_t idx)
{
	size_t	result;
	
	result = 0;
	while(1)
	{
		if (x->si[idx] <= 16)
		{
			result += x->si[idx];
			break;
		}
		else
		{
			result += 16;
		}
		idx++;
	}
	return (result);
}

static size_t	get_size_t_st(t_st *x, void *ptr)
{
	t_st			*dest;
	t_st			*src;

	if (x == NULL)
		return (0);
	src = x;
	while (src)
	{
		if (x->si != NULL)
		{
			if ((size_t)(ptr - x->ptr) < x->size)
				return (return_size(x, (size_t)(ptr - x->ptr) / 16));				
		}
		else
		{
			if (ptr == x->ptr)
				return (x->size);
		}
		dest = src;
		src = dest->next;
	}
	return (0);
}

size_t	get_size(void *ptr)
{
	size_t	size;

	size = get_size_t_st(g_all->tiny, ptr);
	if (size > 0)
		return (size);
	size = get_size_t_st(g_all->small, ptr);
	if (size > 0)
		return (size);
	size = get_size_t_st(g_all->large, ptr);
	if (size > 0)
		return (size);
	return (0);
}

size_t	m_ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	m_ft_strcmp(char *str1, char *str2)
{
	size_t	idx;

	if (!str1 || !str2)
		return (1);
	idx = 0;
	while (str1[idx] && str2[idx])
	{
		if (str1[idx] == str2[idx])
			idx++;
		else
			break ;
	}
	if (str1[idx] || str2[idx])
		return ((unsigned char)str1[idx] - (unsigned char)str2[idx]);
	return (0);
}

void	put_str_fd(int fd, char *str)
{
	size_t	i;

	i = m_ft_strlen(str);
	write(fd, str, i);
}

void	put_num_fd(int fd, size_t num)
{
	char	s;

	if (num < 10)
		s = num + '0';
	else
	{
		put_num_fd(fd, num / 10);
		s = (num % 10) + '0';
	}
	write(fd, &s, 1);
}

t_st	*size_of_return(size_t size)
{
	if (size <= TINY_SIZE && g_all->tiny)
		return (g_all->tiny);
	else if (size > TINY_SIZE && size <= SMALL_SIZE && g_all->small)
		return (g_all->small);
	return (NULL);
}

size_t	resize(size_t size, size_t x)
{
	size_t	result;

	result = size / x;
	if (size % x)
		result++;
	return (result * x);
}
