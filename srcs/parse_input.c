/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:24:30 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/22 12:34:24 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_params(char **params, int len)
{
	char	*str;
	int		i;

	i = -1;
	str = NULL;
	while (++i < len)
	{
		str = ft_strjoin_gnl(str, params[i]);
		if (i + 1 < len)
			str = ft_strjoin_gnl(str, " ");
	}
	return (str);
}

int	check_str_is_valide(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_params(char **str_array)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (str_array[++i])
	{
		if (!check_str_is_valide(str_array[i]))
			exit_error(str_array, NULL);
		j = -1;
		while (str_array[++j])
		{
			len = ft_strlen(str_array[i]);
			if ((int)ft_strlen(str_array[j]) > len && i != j)
				len = ft_strlen(str_array[j]);
		}
	}
}

int	*convert_num(char **params)
{
	int	i;
	int	*arr;
	int	len;

	len = ft_str_array_len(params);
	arr = malloc(sizeof(int) * len);
	i = -1;
	while (params[++i])
		arr[i] = ft_atoi_push_swap(params[i], params, arr);
	return (arr);
}

void	check_duplicate(char **str_arr, int *arr, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (arr[j] == arr[i] && i != j)
				exit_error(str_arr, arr);
		}
	}
}
