#include "../include/fractol.h"

static int	ft_is_valid_char(char c, int *has_dot)
{
	if (c == '.')
	{
		if (*has_dot)
			return (0);
		*has_dot = 1;
		return (1);
	}
	return (c >= '0' && c <= '9');
}

int	ft_is_valid_float(const char *str)
{
	int	i;
	int	has_digit;
	int	has_dot;

	i = 0;
	has_digit = 0;
	has_dot = 0;
	if (!str || !str[0])
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_is_valid_char(str[i], &has_dot) == 0)
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
			has_digit = 1;
		i++;
	}
	return (has_digit);
}

static double	parse_integer(const char **str)
{
	double	result;
	int		digit;

	result = 0.0;
	while (**str != '\0' && **str != '.')
	{
		if (!(**str >= '0' && **str <= '9'))
		{
			ft_printf("Invalid float input for Julia set.\n");
			print_usage();
			exit (0);
		}
		digit = **str - '0';
		if (result > (DBL_MAX - digit) / 10.0)
		{
			ft_printf("Julia set parameters are too large.\n");
			print_usage();
			exit (0);
		}
		result = result * 10.0 + digit;
		(*str)++;
	}
	return (result);
}

static double	parse_fraction(const char **str)
{
	double	result;
	double	divider;

	result = 0.0;
	divider = 10.0;
	if (**str == '\0')
		return (0.0);
	while (**str != '\0')
	{
		if (!(**str >= '0' && **str <= '9'))
		{
			ft_printf("Invalid float input for Julia set.\n");
			print_usage();
			exit (0);
		}
		result += (**str - '0') / divider;
		divider *= 10.0;
		(*str)++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		else
			sign = 1;
		str++;
	}
	result = parse_integer(&str);
	fraction = 0.0;
	if (*str == '.')
	{
		str++;
		fraction = parse_fraction(&str);
	}
	if (result > DBL_MAX - fraction)
		return (sign * DBL_MAX);
	return (sign * (result + fraction));
}
