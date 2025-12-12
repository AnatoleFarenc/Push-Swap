/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:21:03 by anfarenc          #+#    #+#             */
/*   Updated: 2025/11/11 12:15:01 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
