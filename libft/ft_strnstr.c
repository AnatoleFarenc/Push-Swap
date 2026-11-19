#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		if (little[0] == big[i])
		{
			if (ft_strlen(little) > len - i)
				return (NULL);
			if (!ft_strncmp(little, &big[i], ft_strlen(little)))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
