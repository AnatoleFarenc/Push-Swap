/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:06:04 by anfarenc          #+#    #+#             */
/*   Updated: 2025/11/11 12:16:48 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;
	size_t	i;
	size_t	y;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		result[i] = s1[i];
	y = -1;
	while (++y < len_s2)
		result[i + y] = s2[y];
	result[i + y] = '\0';
	return (result);
}
