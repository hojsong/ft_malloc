/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:38:38 by hojsong           #+#    #+#             */
/*   Updated: 2022/11/12 18:34:45 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*fls(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	void	*idx;

	idx = f(lst->content);
	if (idx)
		nl = ft_lstnew(idx);
	else
		return (0);
	if (nl)
		return (nl);
	del(idx);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*nl;

	if (lst == NULL || f == NULL)
		return (0);
	result = NULL;
	nl = fls(lst, f, del);
	while (lst && nl)
	{
		ft_lstadd_back(&result, nl);
		lst = lst->next;
		if (lst)
			nl = fls(lst, f, del);
	}
	if (lst == NULL)
		return (result);
	if (result)
		ft_lstclear(&result, del);
	return (0);
}
