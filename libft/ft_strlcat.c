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
