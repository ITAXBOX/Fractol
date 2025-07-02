#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*answer;

	if (size != 0 && nmemb > 18446744073709551615UL / size)
		return (NULL);
	answer = malloc(nmemb * size);
	if (!answer)
		return (NULL);
	ft_memset(answer, 0, nmemb * size);
	return (answer);
}
