/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:34:24 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/18 19:19:44 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define RA 0
# define RRA 1
# define RB 2
# define RRB 3
# define RR 4
# define RRR 5

typedef struct s_stack
{
	int		*array;
	int		top;
	int		len;
}			t_stack;

typedef struct s_movement
{
	int		nb_ite;
	int		mov;
}			t_movement;

// parsing
char		*join_params(char **params, int len);
void		check_params(char **str_array);
int			*convert_num(char **params);
void		check_duplicate(char **str_arr, int *arr, int len);
int			*parse_params(char **params, int *len);

// linked list
void		initialize_stack(t_stack *stack, int len);
int			stack_is_empty(t_stack *stack);
int			stack_is_full(t_stack *stack);
void		push_on_stack(t_stack *stack, int value);
void		pop_on_stack(t_stack *stack, int *popped);
void		peek_stack(t_stack *stack, int *peeked);
void		print_stack(t_stack a, t_stack b);

// utils
size_t		ft_str_array_len(char **str_array);
void		free_arrays(char **arrays);
void		exit_error(char **str_array, int *arr);
int			ft_atoi_push_swap(const char *str, char **str_array, int *arr,
				int int_max);
int			*ft_copy_int_array(int *dest, int *src, int len);
int			ft_abs(int nb);
int			calc_min(t_stack stack);

// operate
char		*sa(t_stack *stack);
char		*pa(t_stack *a, t_stack *b);
char		*ra(t_stack *a);
char		*rra(t_stack *a);
char		*sb(t_stack *b);
char		*pb(t_stack *b, t_stack *a);
char		*rb(t_stack *b);
char		*rrb(t_stack *b);
char		*ss(t_stack *a, t_stack *b);
char		*rr(t_stack *a, t_stack *b);
char		*rrr(t_stack *a, t_stack *b);

// movement
t_movement	cost_a(t_stack a, int index);
t_movement	cost_b(t_stack b, int index);
int			search_good_place(t_stack a, int value);
int			get_index(t_stack stack, int value);
t_movement	calc_move_a(t_stack a, int value_b);
void		replace_value_in_stack(t_stack *a, t_stack *b);
void		min_to_top(t_stack *a);
void		end_play_move(t_stack *a, t_stack *b, t_movement move_a,
				t_movement move_b);

// list
void		calc_lis(t_stack a, int *len, int *parrent);
int			*set_lis(t_stack a, int *big_len);

// push swap
void		sort_a_stack(t_stack *a, t_stack *b);

#endif