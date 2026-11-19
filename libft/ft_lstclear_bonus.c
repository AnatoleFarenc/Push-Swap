#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*index;
	t_list	*tmp;

	index = *lst;
	while (index)
	{
		tmp = index->next;
		ft_lstdelone(index, del);
		index = tmp;
	}
	*lst = NULL;
}
