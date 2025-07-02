#include "ft_printf.h"

int	ft_print(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnmbr_hexa(va_arg(args, unsigned int), HEX_LOW));
	else if (c == 'X')
		return ((ft_putnmbr_hexa(va_arg(args, unsigned int), HEX_UPP)));
	else
		return (ft_putchar_fd('%', 1), 1);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(str + 1) != '\0' && ft_check_conversion(*(str + 1)) == 1)
				counter += ft_print(args, *(str + 1));
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			counter++;
		}
		str++;
	}
	va_end(args);
	return (counter);
}
