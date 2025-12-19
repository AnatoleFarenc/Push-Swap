/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:53:27 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/19 11:54:00 by anfarenc         ###   ########.fr       */
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

void	min_to_top(t_stack *a)
{
	int			index_min;
	int			min;
	int			i;
	t_movement	mov_a;

	i = -1;
	index_min = 0;
	min = a->array[0];
	while (++i <= a->top)
	{
		if (min > a->array[i])
			index_min = i;
	}
	min = calc_min(*a);
	mov_a = cost_a(*a, index_min);
	i = -1;
	while (a->array[a->top] != min)
	{
		if (mov_a.mov == RA)
			ft_printf("%s\n", ra(a));
		if (mov_a.mov == RRA)
			ft_printf("%s\n", rra(a));
	}
}
