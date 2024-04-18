/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcelar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:37:08 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:34:33 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nod;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		nod = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = nod;
	}
}
