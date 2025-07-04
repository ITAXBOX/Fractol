#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*temp1;
	const unsigned char	*temp2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	temp1 = (unsigned char *)dest;
	temp2 = (unsigned const char *)src;
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (dest);
}
