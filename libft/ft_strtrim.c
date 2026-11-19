#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*n_str;
	size_t	size;

	start = 0;
	end = ft_strlen(s1);
	if ((s1[0] == '\0' && set[0] == '\0') || s1[0] == '\0')
		return (n_str = ft_strdup(""));
	while (ft_strchr(set, s1[start]))
		start++;
	if (start >= end)
		return (n_str = ft_strdup(""));
	while (ft_strchr(set, s1[end]))
		end--;
	size = end - start + 1;
	n_str = malloc(sizeof(char) * size + 1);
	if (!n_str)
		return (NULL);
	ft_strlcpy(n_str, (char *)&s1[start], size + 1);
	return (n_str);
}
