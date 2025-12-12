/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 08:40:58 by anfarenc          #+#    #+#             */
/*   Updated: 2025/11/09 19:57:40 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_src;
	int		i;
	char	*dest;

	len_src = ft_strlen(s);
	dest = malloc(sizeof(char) * (len_src + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < (int)len_src)
		dest[i] = s[i];
	dest[i] = '\0';
	return (dest);
}
