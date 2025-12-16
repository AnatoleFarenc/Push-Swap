/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:53:27 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/16 10:57:01 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_lis(int nb, int *lis_arr, int len_lis)
{
	int	i;
	i = -1;
	while (++i < len_lis)
	{
		if (nb == lis_arr[i])
			return (1);
	}
	return (0);
}

void	sort_a_stack(t_stack *a, t_stack *b)
{
	int	*lis_arr;
	int	i;
	int	len_lis;
	int	value;

	lis_arr = set_lis(*a, &len_lis);
	i = -1;
	while (++i < a->len)
	{
		peek_stack(a, &value);
		if (!check_lis(value, lis_arr, len_lis))
			ft_printf("%s\n", pb(b, a));
		else
			ft_printf("%s\n", ra(a));
	}
	free(lis_arr);
}