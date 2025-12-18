/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:33:47 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/18 09:46:24 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sb(t_stack *b)
{
	int	value_1;
	int	value_2;

	if (stack_is_empty(b))
		return ("sb");
	pop_on_stack(b, &value_1);
	pop_on_stack(b, &value_2);
	push_on_stack(b, value_1);
	push_on_stack(b, value_2);
	return ("sb");
}

char	*pb(t_stack *b, t_stack *a)
{
	int	value_a;

	if (stack_is_empty(a))
		return ("pb");
	pop_on_stack(a, &value_a);
	push_on_stack(b, value_a);
	return ("pb");
}

char	*rb(t_stack *b)
{
	t_stack	tmp;
	int		top_value;
	int		value;

	initialize_stack(&tmp, b->len);
	pop_on_stack(b, &top_value);
	while (!stack_is_empty(b))
	{
		pop_on_stack(b, &value);
		push_on_stack(&tmp, value);
	}
	push_on_stack(b, top_value);
	while (!stack_is_empty(&tmp))
	{
		pop_on_stack(&tmp, &value);
		push_on_stack(b, value);
	}
	free(tmp.array);
	return ("rb");
}

char	*rrb(t_stack *b)
{
	t_stack	tmp;
	int		last_value;
	int		value;

	initialize_stack(&tmp, b->len);
	while (!stack_is_empty(b))
	{
		pop_on_stack(b, &value);
		push_on_stack(&tmp, value);
	}
	pop_on_stack(&tmp, &last_value);
	while (!stack_is_empty(&tmp))
	{
		pop_on_stack(&tmp, &value);
		push_on_stack(b, value);
	}
	push_on_stack(b, last_value);
	free(tmp.array);
	return ("rrb");
}
