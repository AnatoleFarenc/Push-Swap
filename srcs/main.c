/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:30:12 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/19 11:55:25 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arv)
{
	int		*values;
	int		i;
	t_stack	a;
	t_stack	b;
	int		len;

	if (arc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	len = arc - 1;
	values = parse_params(&arv[1], &len);
	initialize_stack(&a, len);
	initialize_stack(&b, len);
	i = len;
	while (i--)
		push_on_stack(&a, values[i]);
	sort_a_stack(&a, &b);
	replace_value_in_stack(&a, &b);
	min_to_top(&a);
	free(a.array);
	free(b.array);
	free(values);
	return (EXIT_SUCCESS);
}
