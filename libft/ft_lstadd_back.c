#include <stdlib.h>
#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		t_list *current = *lst;
        while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	new->next = NULL;
}
