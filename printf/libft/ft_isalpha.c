#include "libft.h"

int	ft_isalpha(int c)
{
	char	a;

	a = (char) c;
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	return (0);
}
