/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:48:04 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/18 09:43:46 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_lis(t_stack a, int *len, int *parrent)
{
	int	i;
	int	j;

	i = a.len;
	while (i-- > 0)
	{
		parrent[i] = -1;
		len[i] = 1;
		j = i;
		while (++j < a.len)
		{
			if (a.array[i] > a.array[j] && len[j] >= len[i])
			{
				len[i] = len[j] + 1;
				parrent[i] = j;
			}
		}
	}
}

int	bigest_len(int *len_array, int len)
{
	int	i;
	int	index_len;

	i = len;
	index_len = len - 1;
	while (i-- > 0)
	{
		if (len_array[index_len] < len_array[i])
			index_len = i;
	}
	return (index_len);
}

void	copy_in_lis(t_stack a, int *parrent, int index, int *array)
{
	int	i;

	i = 0;
	while (index != -1)
	{
		array[i] = a.array[index];
		index = parrent[index];
		i++;
	}
}

int	*set_lis(t_stack a, int *big_len)
{
	int	*len;
	int	*parrent;
	int	*array;
	int	index;

	array = NULL;
	len = malloc(sizeof(int) * a.len);
	parrent = malloc(sizeof(int) * a.len);
	calc_lis(a, len, parrent);
	index = bigest_len(len, a.len);
	*big_len = len[index];
	array = malloc(sizeof(int) * *big_len);
	copy_in_lis(a, parrent, index, array);
	free(len);
	free(parrent);
	return (array);
}
