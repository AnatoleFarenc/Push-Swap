/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_option_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:59:01 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/18 10:00:44 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	peek_stack(t_stack *stack, int *peeked)
{
	if (stack_is_empty(stack))
	{
		peeked = NULL;
		return ;
	}
	*peeked = stack->array[stack->top];
}

void	print_stack(t_stack a, t_stack b)
{
	int	popped;

	while (!stack_is_empty(&a))
	{
		pop_on_stack(&a, &popped);
		ft_printf("%d ", popped);
		if (!stack_is_empty(&b))
		{
			pop_on_stack(&b, &popped);
			ft_printf("%d", popped);
		}
		ft_printf("\n");
	}
	ft_printf("_ _\na b\n");
}
