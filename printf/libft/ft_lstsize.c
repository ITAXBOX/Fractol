#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		answer;
	t_list	*temp;

	answer = 0;
	temp = lst;
	while (temp != NULL)
	{
		answer++;
		temp = temp -> next;
	}
	return (answer);
}
