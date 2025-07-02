#include "libft.h"

static void	ft_strcpy(char	*result, char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (!s || !f)
		return (NULL);
	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, s);
	while (result[i] != '\0')
	{
		result[i] = (*f)(i, result[i]);
		i++;
	}
	return (result);
}
