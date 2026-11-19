#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*next_elem;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	next_elem = new_list->next;
	lst = lst->next;
	while (lst)
	{
		next_elem = ft_lstnew((*f)(lst->content));
		if (!next_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, next_elem);
		lst = lst->next;
		next_elem = next_elem->next;
	}
	return (new_list);
}
