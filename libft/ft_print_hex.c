#include "libft.h"

int	ft_print_dec_to_hex(unsigned long long int nb, int is_up)
{
	char	dict[16];
	int		i;
	char	letter;
	int		counter;

	letter = 'a';
	if (is_up)
		letter = 'A';
	counter = 1;
	i = -1;
	while (++i < 10)
		dict[i] = '0' + i;
	i--;
	while (++i < 16)
		dict[i] = letter + (i - 10);
	if (nb < 16)
		ft_putchar_fd(dict[nb], 1);
	else
	{
		counter += ft_print_dec_to_hex(nb / 16, is_up);
		ft_putchar_fd(dict[nb % 16], 1);
	}
	return (counter);
}

int	ft_print_addr(unsigned long long int nb)
{
	if (!nb)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (ft_print_dec_to_hex(nb, 0) + 2);
}
