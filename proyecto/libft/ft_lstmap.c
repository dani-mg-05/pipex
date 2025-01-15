/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:08:09 by damedina          #+#    #+#             */
/*   Updated: 2023/09/27 16:23:16 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_f(void *tmp, void (*del)(void *))
{
	del(tmp);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_node;
	t_list	*list;
	void	*tmp;

	if (!lst)
		return (0);
	node = lst->next;
	tmp = f(lst->content);
	list = ft_lstnew(tmp);
	if (!list)
		return (free_f(tmp, del));
	while (node)
	{
		tmp = f(node->content);
		new_node = ft_lstnew(tmp);
		if (!new_node)
		{
			ft_lstclear(&list, del);
			return (free_f(tmp, del));
		}
		ft_lstadd_back(&list, new_node);
		node = node->next;
	}
	return (list);
}
