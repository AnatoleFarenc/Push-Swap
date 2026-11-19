#include "libft.h"

int	ft_print_dec(long int n)
{
	size_t	counter;

	counter = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		counter += 1;
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', 1);
	else
	{
		counter += ft_print_dec(n / 10);
		ft_putchar_fd((n % 10) + '0', 1);
	}
	return (counter);
}
