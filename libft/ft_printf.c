#include "libft.h"

static int	ft_print_value(char c, va_list argv)
{
	if (c == 'c')
		return (ft_print_char((int)va_arg(argv, int)));
	else if (c == 's')
		return (ft_print_string((char *)va_arg(argv, char *)));
	else if (c == '%')
		return (ft_print_char('%'));
	else if (c == 'p')
		return (ft_print_addr((unsigned long)va_arg(argv, unsigned long)));
	else if (c == 'x')
		return (ft_print_dec_to_hex((unsigned int)va_arg(argv, unsigned), 0));
	else if (c == 'X')
		return (ft_print_dec_to_hex((unsigned int)va_arg(argv, unsigned), 1));
	else if (c == 'i' || c == 'd')
		return (ft_print_dec((int)va_arg(argv, int)));
	else if (c == 'u')
		return (ft_print_dec((unsigned int)va_arg(argv, unsigned int)));
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(c, 1);
		return (2);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	argv;
	int		i;
	int		len;

	va_start(argv, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_print_value(str[i + 1], argv);
			i += 2;
		}
		else
		{
			ft_putchar_fd((char)str[i], 1);
			i++;
			len++;
		}
	}
	va_end(argv);
	return (len);
}
