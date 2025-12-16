/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_stack_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:31:36 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/16 19:47:20 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost (t_movement a, t_movement b)
{
	if ((a.mov == RA && b.mov == RB) || (a.mov == RRA && b.mov == RRB))
	{
		if (a.nb_ite > b.nb_ite)
			return (a.nb_ite);
		return (b.nb_ite);
	}
	return (a.nb_ite + b.nb_ite);
}

void	play_mod(t_stack s_a, t_stack s_b, t_movement a, t_movement b)
{
	if ((a.mov == RA && b.mov == RB) || (a.mov == RRA && b.mov == RRB))
	{
		while (a.nb_ite && b.nb_ite)
		{
			if (a.mov == RA)
				ft_printf("%s\n", rr(&s_a, &s_b));
			if (a.mov == RRA)
				ft_printf("%s\n", rrr(&s_a, &s_b));
			a.nb_ite--;
			b.nb_ite--;
		}
	}
	while (a.nb_ite)
	{
		if (a.mov == RA)
			ft_printf("%s\n", ra(&s_a));
		if (a.mov == RRA)
			ft_printf("%s\n", rra(&s_a));
		a.nb_ite--;
	}
	while(b.nb_ite)
	{
		if (b.mov == RB)
			ft_printf("%s\n", rb(&s_b));
		if (b.mov == RRB)
			ft_printf("%s\n", rb(&s_b));
		b.nb_ite--;
	}
}

void	replace_value_on_stack(t_stack a, t_stack b)
{
	int	j;
	int	cost;
	int	index;

	while (!stack_is_empty(&b))
	{
		cost = b.len;
		index = b.top;
		j = -1;
		while (++j < b.top)
		{
			if (cost > calc_cost(calc_move_a(a, b.array[j]), cost_b(b, j)))
			{
				cost = calc_cost(calc_move_a(a, b.array[j]), cost_b(b, j));
				index = j;
			}		
		}
		play_mod(a, b, calc_move_a(a, b.array[index]), cost_b(b, index));
		ft_printf("%s\n", pa(&a, &b));
	}
}
