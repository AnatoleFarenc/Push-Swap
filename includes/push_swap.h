/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:34:24 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/11 12:46:45 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_stack
{
	int	*array;
	int	top;
	int	len;
}	t_stack;

//parsing
char	*join_params(char **params, int len);
int		*parse_params(char **params, int *len);

//linked list
void	initialize_stack(t_stack *stack, int len);
int		stack_is_empty(t_stack *stack);
int		stack_is_full(t_stack *stack);
void	push_on_stack(t_stack *stack, int value);
void	pop_on_stack(t_stack *stack, int *popped);
void	peek_stack(t_stack *stack, int *peeked);
void	print_stack(t_stack a, t_stack b);

//utils
size_t	ft_str_array_len(char **str_array);
void	free_arrays(char **arrays);
void	exit_error(char **str_array, int *arr);
int	ft_atoi_push_swap(const char *str, char **str_array, int *arr, int int_max);
int		*ft_copy_int_array(int *dest, int *src, int len);

//operate
char	*sa(t_stack *stack);
char	*pa(t_stack *a, t_stack *b);
char	*ra(t_stack *a);
char	*rra(t_stack *a);
char	*sb(t_stack *b);
char	*pb(t_stack *b, t_stack *a);
char	*rb(t_stack *b);
char	*rrb(t_stack *b);
char	*ss(t_stack *a, t_stack *b);
char	*rr(t_stack *a, t_stack *b);
char	*rrr(t_stack *a, t_stack *b);

#endif