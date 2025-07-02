#include "ft_printf.h"

int	ft_check_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	ft_num_size(int n)
{
	int		answer;
	long	temp;

	answer = 0;
	temp = n;
	if (n == 0)
		return (1);
	if (temp < 0)
	{
		temp = -temp;
		answer = 1;
	}
	while (temp != 0)
	{
		temp /= 10;
		answer++;
	}
	return (answer);
}

int	ft_putnmbr_hexa(unsigned int nbr, char *base)
{
	int	counter;

	counter = 0;
	if (nbr >= 16)
		counter = ft_putnmbr_hexa(nbr / 16, base);
	ft_putchar_fd(base[nbr % 16], 1);
	return (counter + 1);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n >= 10)
		counter += ft_putnbr_unsigned(n / 10);
	counter += (ft_putchar_fd(n % 10 + '0', 1), 1);
	return (counter);
}
