/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:25:06 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/28 16:15:15 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	play_operation(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(operation, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(operation, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(operation, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(operation, "pb\n", 3))
		pb(b, a);
	else if (!ft_strncmp(operation, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(operation, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(operation, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(operation, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	check_value(t_stack *a, t_stack *b)
{
	char	*operation;
	int		i;

	operation = get_next_line(0);
	while (operation)
	{
		if (!play_operation(a, b, operation))
		{
			free(operation);
			return (-1);
		}
		free(operation);
		operation = get_next_line(0);
	}
	free(operation);
	i = -1;
	while (++i < a->top)
	{
		if (a->array[i] < a->array[i + 1])
			return (0);
	}
	if (!stack_is_empty(b))
		return (0);
	return (1);
}

int	main(int arc, char **arv)
{
	int		*values;
	int		i;
	t_stack	a;
	t_stack	b;
	int		len;

	if (arc < 2)
		return (EXIT_FAILURE);
	len = arc - 1;
	values = parse_params(&arv[1], &len);
	initialize_stack(&a, len);
	initialize_stack(&b, len);
	i = len;
	while (i--)
		push_on_stack(&a, values[i]);
	i = check_value(&a, &b);
	if (i == 1)
		ft_printf("OK\n");
	else if (i == -1)
		ft_putstr_fd("Error\n", 2);
	else if (i == 0)
		ft_printf("KO\n");
	free(a.array);
	free(b.array);
	return (free(values), EXIT_SUCCESS);
}
