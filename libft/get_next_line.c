/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfarenc <anfarenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:45:09 by anfarenc          #+#    #+#             */
/*   Updated: 2025/12/08 17:13:54 by anfarenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_grow_stache(int fd, char *stache)
{
	char	*buff;
	int		n_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buff[BUFFER_SIZE] = '\0';
	if (!buff)
		return (NULL);
	n_bytes = 1;
	while (!ft_strchr(stache, '\n') && n_bytes)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
			return (free(buff), NULL);
		buff[n_bytes] = '\0';
		stache = ft_strjoin_gnl(stache, buff);
	}
	free(buff);
	if (!n_bytes && !stache[0])
	{
		free(stache);
		return (NULL);
	}
	return (stache);
}

char	*ft_get_hair(char *stache)
{
	int		i;
	char	*line;

	i = 0;
	while (stache[i] && stache[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stache[i] && stache[i] != '\n')
	{
		line[i] = stache[i];
		i++;
	}
	if (stache[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_trim_stache(char *stache)
{
	int		i;
	int		j;
	char	*trimmed_stache;

	i = 0;
	if (!stache)
		return (NULL);
	if (!ft_strchr(stache, '\n'))
	{
		free(stache);
		return (NULL);
	}
	while (stache[i] && stache[i] != '\n')
		i++;
	trimmed_stache = ft_calloc(ft_strlen(&stache[i]) + 2, sizeof(char));
	if (!trimmed_stache)
		return (NULL);
	j = 0;
	if (stache[i] == '\n')
		i++;
	while (stache[i])
		trimmed_stache[j++] = stache[i++];
	free(stache);
	return (trimmed_stache);
}

char	*get_next_line(int fd)
{
	static char	*stache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stache = ft_grow_stache(fd, stache);
	if (!stache)
		return (NULL);
	line = ft_get_hair(stache);
	stache = ft_trim_stache(stache);
	return (line);
}
