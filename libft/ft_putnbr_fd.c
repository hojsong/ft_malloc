/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:22:22 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:13 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_int(int n, int fd)
{
	char	c;

	c = n + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	a;

	if (n >= -9 && n <= 9)
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		ft_put_int(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		a = n % 10;
		if (a < 0)
			a *= -1;
		ft_put_int(a, fd);
	}
}
/*
int main (void)
{
	ft_putnbr_fd(-2147483648, 1);
}*/
