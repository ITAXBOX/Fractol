#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;
	unsigned char		target;
	size_t				i;

	if (!s)
		return (NULL);
	temp = (const unsigned char *)s;
	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (temp[i] == target)
			return ((void *)(temp + i));
		i++;
	}
	return (NULL);
}
