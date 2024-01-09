/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:02:59 by ecortes-          #+#    #+#             */
/*   Updated: 2023/09/20 16:03:00 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mylist;
	t_list	*new_node;
	void	*new_content;

	mylist = NULL;
	while (lst != NULL && f != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			if (del != NULL && new_content != NULL)
				del(new_content);
			ft_lstclear(&mylist, del);
			return (NULL);
		}
		ft_lstadd_back(&mylist, new_node);
		lst = lst->next;
	}
	return (mylist);
}
