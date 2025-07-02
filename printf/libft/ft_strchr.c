#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	temp;

	if (!s)
		return (NULL);
	i = 0;
	temp = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == temp)
			return ((char *)(s + i));
		i++;
	}
	if (temp == '\0')
		return ((char *)(s + i));
	return (NULL);
}
