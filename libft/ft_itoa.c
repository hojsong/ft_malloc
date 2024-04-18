/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:25:32 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:34:26 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_msi(int n)
{
	int	b;
	int	i;

	b = n;
	i = 0;
	while (b != 0)
	{
		b /= 10;
		i++;
	}
	if (n <= 0)
		i++;
	return (i);
}

void	ft_lsw(char *str, int len)
{
	int		i;
	char	c;

	i = 0;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
}

void	ft_nbr(int n, char *str)
{
	int	nb;

	if (n >= -9 && n <= 9)
	{
		if (n < 0)
		{
			n *= -1;
			str[0] = n + '0';
			str[1] = '-';
		}
		else
			str[0] = n + '0';
	}
	else
	{
		ft_nbr(n / 10, &str[1]);
		nb = n % 10;
		if (nb < 0)
			nb *= -1;
		str[0] = nb + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_msi(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	ft_nbr(n, str);
	str[size] = '\0';
	ft_lsw(str, size);
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char *str;
	int i = -2124;

	str = ft_itoa(i);
	printf("%s\n",str);
}*/
