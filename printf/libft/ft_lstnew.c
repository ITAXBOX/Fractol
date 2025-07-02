#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*answer;

	answer = malloc(sizeof(t_list));
	if (!answer)
		return (NULL);
	answer -> content = content;
	answer -> next = NULL;
	return (answer);
}
