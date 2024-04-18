/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:11:46 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:35:25 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_len(char *c)
{
	unsigned int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	len = ft_len(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
