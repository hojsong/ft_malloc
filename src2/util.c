/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:21:39 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/22 10:42:30 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc2.h"

t_sta	*g_all;

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
	if (size < TINY_SIZE)
		return (g_all->tiny);
	else if (size < SMALL_SIZE)
		return (g_all->small);
	else if (size > SMALL_SIZE)
		return (g_all->large);
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
