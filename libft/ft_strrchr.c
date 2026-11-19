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
