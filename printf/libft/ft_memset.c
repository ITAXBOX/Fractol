#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	if (!s)
		return (NULL);
	i = 0;
	temp = (unsigned char *) s;
	while (i < n)
	{
		temp[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
