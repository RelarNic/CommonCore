#include <stdlib.h>
#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *temp;
	
	if (!lst || !f)
		return ;
	while (!lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, f);
		*lst = temp;
	}
	*lst = NULL;
}