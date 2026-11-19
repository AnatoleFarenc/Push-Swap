#include "push_swap.h"

void	initialize_stack(t_stack *stack, int len)
{
	stack->top = -1;
	stack->array = malloc(sizeof(int) * len);
	stack->len = len;
}

int	stack_is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

int	stack_is_full(t_stack *stack)
{
	return (stack->top == stack->len - 1);
}

void	push_on_stack(t_stack *stack, int value)
{
	if (stack_is_full(stack))
		return ;
	stack->array[++stack->top] = value;
}

void	pop_on_stack(t_stack *stack, int *popped)
{
	if (stack_is_empty(stack))
	{
		popped = NULL;
		return ;
	}
	*popped = stack->array[stack->top];
	stack->top--;
}
