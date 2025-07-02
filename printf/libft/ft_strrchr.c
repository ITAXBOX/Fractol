#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	temp;

	if (!s)
		return (NULL);
	temp = (char)c;
	i = 0;
	while (s[i])
		i++;
	while (i > 0)
	{
		if (s[i] == temp)
			return ((char *)(s + i));
		i--;
	}
	if (s[i] == temp)
		return ((char *)(s + i));
	return (NULL);
}
