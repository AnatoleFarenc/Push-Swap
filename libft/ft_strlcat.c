/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:24:16 by anfarenc          #+#    #+#             */
/*   Updated: 2025/11/11 12:16:59 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		y;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	i = dest_len;
	y = -1;
	if (dest_len >= size)
		return (src_len + size);
	while (i < size - 1 && src[++y])
	{
		dst[i] = src[y];
		i++;
	}
	dst[i] = '\0';
	return (src_len + dest_len);
}
