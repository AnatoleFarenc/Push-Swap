/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_stack_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:31:36 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/18 11:19:36 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	optimize_cost(t_movement move_a, t_movement move_b)
{
	if ((move_a.mov == RA && move_b.mov == RB) || (move_a.mov == RRA
			&& move_b.mov == RRB))
	{
		if (move_a.nb_ite >= move_b.nb_ite)
			return (move_a.nb_ite);
		else
			return (move_b.nb_ite);
	}
	return (move_a.nb_ite + move_b.nb_ite);
}

int	best_move(t_stack a, t_stack b)
{
	int			index;
	int			cost;
	t_movement	move_b;
	t_movement	move_a;
	int			i;

	i = -1;
	index = b.top;
	cost = b.len;
	while (++i <= b.top)
	{
		move_b = cost_b(b, i);
		move_a = calc_move_a(a, b.array[i]);
		if (cost > optimize_cost(move_a, move_b))
		{
			cost = optimize_cost(move_a, move_b);
			index = i;
		}
	}
	return (index);
}

void	play_move(t_stack *a, t_stack *b, t_movement move_a, t_movement move_b)
{
	if ((move_a.mov == RA && move_b.mov == RB) || (move_a.mov == RRA
			&& move_b.mov == RRB))
	{
		if (move_a.mov == RA)
		{
			while (move_a.nb_ite && move_b.nb_ite)
			{
				ft_printf("%s\n", rr(a, b));
				move_a.nb_ite--;
				move_b.nb_ite--;
			}
		}
		if (move_a.mov == RRA)
		{
			while (move_a.nb_ite && move_b.nb_ite)
			{
				ft_printf("%s\n", rrr(a, b));
				move_a.nb_ite--;
				move_b.nb_ite--;
			}
		}
	}
	end_play_move(a, b, move_a, move_b);
}

void	replace_value_in_stack(t_stack *a, t_stack *b)
{
	t_movement	move_a;
	t_movement	move_b;
	int			index;

	while (!stack_is_empty(b))
	{
		index = best_move(*a, *b);
		move_a = calc_move_a(*a, b->array[index]);
		move_b = cost_b(*b, index);
		play_move(a, b, move_a, move_b);
		ft_printf("%s\n", pa(a, b));
	}
}
