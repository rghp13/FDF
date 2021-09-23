/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:15:57 by rponsonn          #+#    #+#             */
/*   Updated: 2021/07/09 12:25:56 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*head;
	t_list	*tmp;
	t_list	*hold;

	if (!lst)
		return (NULL);
	head = ft_lstnew((*f)(lst->content));
	if (head == NULL)
		return (NULL);
	tmp = lst->next;
	while (tmp)
	{
		hold = ft_lstnew((*f)(tmp->content));
		if (hold == NULL)
		{
			ft_lstclear(&head, d);
			return (NULL);
		}
		ft_lstadd_back(&head, hold);
		tmp = tmp->next;
	}
	return (head);
}
