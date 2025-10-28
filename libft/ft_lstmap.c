/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 22:48:53 by sjuarez           #+#    #+#             */
/*   Updated: 2025/10/28 16:47:06 by sjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*clear_list(t_list *newlst, void (*del)(void *), void *new_content)
{
	if (new_content)
		del(new_content);
	ft_lstclear(&newlst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new_node;
	t_list	*last_node;
	void	*new_content;

	last_node = NULL;
	newlst = NULL;
	while (lst && f && del)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node || !new_content)
		{
			return (clear_list(newlst, del, new_content));
		}
		if (!newlst)
			newlst = new_node;
		else
			last_node->next = new_node;
		new_node->next = NULL;
		last_node = new_node;
		lst = lst->next;
	}
	return (newlst);
}
