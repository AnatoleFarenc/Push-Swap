/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:05:31 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/19 09:12:53 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_str_array_len(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
		i++;
	return (i);
}

int	*ft_copy_int_array(int *dest, int *src, int len)
{
	int	i;

	if (!src)
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = src[i];
	return (dest);
}

void	free_arrays(char **arrays)
{
	int	i;

	i = -1;
	while (arrays[++i])
		free(arrays[i]);
	free(arrays);
}

void	exit_error(char **str_array, int *arr)
{
	ft_putstr_fd("Error\n", 2);
	if (arr)
		free(arr);
	free_arrays(str_array);
	exit(EXIT_FAILURE);
}
