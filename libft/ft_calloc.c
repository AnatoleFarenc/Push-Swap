#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	result = malloc(size * nmemb);
	if (!result)
		return (NULL);
	ft_bzero(result, size * nmemb);
	return (result);
}
