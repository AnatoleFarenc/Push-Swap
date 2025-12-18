/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:33:47 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/18 09:47:44 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sa(t_stack *a)
{
	int	value_1;
	int	value_2;

	if (stack_is_empty(a))
		return ("sa");
	pop_on_stack(a, &value_1);
	pop_on_stack(a, &value_2);
	push_on_stack(a, value_1);
	push_on_stack(a, value_2);
	return ("sa");
}

char	*pa(t_stack *a, t_stack *b)
{
	int	value_b;

	if (stack_is_empty(b))
		return ("pa");
	pop_on_stack(b, &value_b);
	push_on_stack(a, value_b);
	return ("pa");
}

char	*ra(t_stack *a)
{
	t_stack	tmp;
	int		top_value;
	int		value;

	initialize_stack(&tmp, a->len);
	pop_on_stack(a, &top_value);
	while (!stack_is_empty(a))
	{
		pop_on_stack(a, &value);
		push_on_stack(&tmp, value);
	}
	push_on_stack(a, top_value);
	while (!stack_is_empty(&tmp))
	{
		pop_on_stack(&tmp, &value);
		push_on_stack(a, value);
	}
	free(tmp.array);
	return ("ra");
}

char	*rra(t_stack *a)
{
	t_stack	tmp;
	int		last_value;
	int		value;

	initialize_stack(&tmp, a->len);
	while (!stack_is_empty(a))
	{
		pop_on_stack(a, &value);
		push_on_stack(&tmp, value);
	}
	pop_on_stack(&tmp, &last_value);
	while (!stack_is_empty(&tmp))
	{
		pop_on_stack(&tmp, &value);
		push_on_stack(a, value);
	}
	push_on_stack(a, last_value);
	free(tmp.array);
	return ("rra");
}
