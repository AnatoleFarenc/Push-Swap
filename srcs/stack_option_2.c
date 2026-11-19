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
