/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:04:46 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/28 16:22:34 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sort(t_stack a)
{
	int	i;

	i = -1;
	while (++i < a.top)
	{
		if (a.array[i] < a.array[i + 1])
			return (0);
	}
	return (1);
}

void	three_sort_stack(t_stack *a)
{
	int	top;
	int	bot;
	int	mid;

	top = a->array[2];
	mid = a->array[1];
	bot = a->array[0];
	if (top > mid && top < bot)
		ft_printf("%s\n", sa(a));
	else if (top > mid && mid > bot)
		ft_printf("%s\n%s\n", sa(a), rra(a));
	else if (top > mid && mid < bot && top > bot)
		ft_printf("%s\n", ra(a));
	else if (top < mid && mid > bot && bot > top)
		ft_printf("%s\n%s\n", sa(a), ra(a));
	else if (top < mid && top > bot && mid > bot)
		ft_printf("%s\n", rra(a));
}

void	five_sort_stack(t_stack *a, t_stack *b)
{
	while (a->top >= 3)
		ft_printf("%s\n", pb(b, a));
	three_sort_stack(a);
	replace_value_in_stack(a, b);
	min_to_top(a);
}

int	special_case(t_stack *a, t_stack *b)
{
	if (check_if_sort(*a))
		return (1);
	if (a->len == 3)
	{
		three_sort_stack(a);
		return (1);
	}
	if (a->len == 5 || a->len == 4)
	{
		five_sort_stack(a, b);
		return (1);
	}
	return (0);
}
