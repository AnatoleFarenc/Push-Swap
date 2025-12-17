/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 08:22:00 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/17 18:11:02 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_movement cost_a(t_stack a, int index)
{
	t_movement	a_mov;
	
	if (a.top - index <= index +1)
	{
		a_mov.mov = RA;
		a_mov.nb_ite = a.top - index;
	}
	else
	{
		a_mov.mov = RRA;
		a_mov.nb_ite = index + 1;
	}
	return (a_mov);
}

t_movement cost_b(t_stack b, int index)
{
	t_movement	b_mov;
	
	if (b.top - index <= index +1)
	{
		b_mov.mov = RB;
		b_mov.nb_ite = b.top - index;
	}
	else
	{
		b_mov.mov = RRB;
		b_mov.nb_ite = index + 1;
	}
	return (b_mov);
}

int	search_good_place(t_stack a, int value)
{
	int	i;
	int	next_value;
	int	min;

	i = -1;
	min = a.array[0];
	next_value = value;
	while (++i <= a.top)
	{
		if (a.array[i] > next_value)
			next_value = a.array[i];
		if (a.array[i] < min)
			min = a.array[i];
	}
	if (next_value == value)
		return (min);
	i = -1;
	while (++i <= a.top)
	{
		if (a.array[i] > value)
		{
			if (a.array[i] - value < next_value - value)
				next_value = a.array[i];
		}
	}
	return (next_value);
}

t_movement calc_move_a(t_stack a, int value_b)
{
	int value_a;
	t_movement move_a;

	value_a = search_good_place(a, value_b);
	move_a = cost_a(a, get_index(a, value_a));
	return (move_a);
}

int	get_index(t_stack stack, int value)
{
	int	i;

	if (stack_is_empty(&stack))
		return (0);
	i = -1;
	while (++i <= stack.top)
	{
		if (stack.array[i] == value)
			return (i);
	}
	return (i);
}
