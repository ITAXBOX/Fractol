#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	n;
	size_t	i;
	char	*answer;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	answer = malloc(sizeof(char) * (n + 1));
	if (!answer)
		return (NULL);
	i = 0;
	while (i < n)
	{
		answer[i] = s[i];
		i++;
	}
	answer[i] = '\0';
	return (answer);
}
