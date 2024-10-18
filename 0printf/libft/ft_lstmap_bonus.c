/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njulia-c <njulia-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:08:25 by njulia-c          #+#    #+#             */
/*   Updated: 2024/10/17 18:32:08 by njulia-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node_result;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		node_result = ft_lstnew(f(lst->content));
		if (!node_result)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, node_result);
		lst = lst->next;
	}
	return (result);
}
