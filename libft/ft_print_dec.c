/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:04:29 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/08 17:08:11 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_dec(long int n)
{
	size_t	counter;

	counter = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		counter += 1;
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', 1);
	else
	{
		counter += ft_print_dec(n / 10);
		ft_putchar_fd((n % 10) + '0', 1);
	}
	return (counter);
}
