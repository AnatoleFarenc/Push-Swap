#include "push_swap.h"

int	ft_check_overflow(int value, char digit, int sign)
{
	int	max_digit;

	max_digit = 7;
	if (sign == -1)
		max_digit = 8;
	if (value > INT_MAX / 10)
		return (0);
	if (value == INT_MAX / 10 && (digit - '0') > max_digit)
		return (0);
	return (1);
}

int	ft_atoi_push_swap(const char *str, char **str_array, int *arr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!ft_check_overflow(res, str[i], sign))
			exit_error(str_array, arr);
		res = res * 10 + (str[i++] - '0');
	}
	return (res * sign);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb *= -1);
	return (nb);
}

int	calc_min(t_stack stack)
{
	int	i;
	int	min;

	min = stack.array[0];
	i = -1;
	while (++i <= stack.top)
	{
		if (stack.array[i] < min)
			min = stack.array[i];
	}
	return (min);
}

void	end_play_move(t_stack *a, t_stack *b, t_movement m_a, t_movement m_b)
{
	while (m_a.nb_ite)
	{
		if (m_a.mov == RA)
			ft_printf("%s\n", ra(a));
		if (m_a.mov == RRA)
			ft_printf("%s\n", rra(a));
		m_a.nb_ite--;
	}
	while (m_b.nb_ite)
	{
		if (m_b.mov == RB)
			ft_printf("%s\n", rb(b));
		if (m_b.mov == RRB)
			ft_printf("%s\n", rrb(b));
		m_b.nb_ite--;
	}
}
