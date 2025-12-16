/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 08:22:00 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/16 19:48:33 by anfarenc         ###   ########.fr       */
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

	i = a.top;
	while (i-- > 0)
	{
		if (value < a.array[i])
			break;
	}
	return (a.array[i]);
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
	while (++i < stack.top + 1)
	{
		if (stack.array[i] == value)
			return (i);
	}
	return (i);
}
