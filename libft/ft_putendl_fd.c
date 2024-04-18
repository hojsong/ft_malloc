/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:08:09 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:10 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_llen(char *c)
{
	unsigned int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	len;

	if (s == NULL || fd < 0)
		return ;
	len = ft_llen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}
/*
int main (void)
{
	char str[200] = "I am groot";

	ft_putendl_fd(str,2);
}*/
