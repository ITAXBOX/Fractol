#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	answer;

	i = 0;
	sign = 1;
	answer = 0;
	if (!nptr)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		answer *= 10;
		answer += nptr[i] - '0';
		i++;
	}
	return (sign * answer);
}
