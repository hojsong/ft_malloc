/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:40:53 by hojsong           #+#    #+#             */
/*   Updated: 2024/04/13 04:03:31 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/malloc.h"

t_sta	*g_all;
int		g_blakcs_size;
int		g_blakc_one;

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

size_t	m_ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

void	put_hex_num(int fd, unsigned long long ptr, int idx)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (idx == 7)
		put_str_fd(fd, "0x");
	else
		put_hex_num(fd, ptr / g_blakc_one, idx + 1);
	write(fd, &str[ptr % g_blakc_one], 1);
}
