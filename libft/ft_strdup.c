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
