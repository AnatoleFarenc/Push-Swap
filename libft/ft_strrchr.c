/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:05:11 by anfarenc          #+#    #+#             */
/*   Updated: 2025/11/11 12:17:38 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;
	char	b;

	b = (char)c;
	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == b)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == b)
		res = (char *)&s[i];
	return (res);
}
