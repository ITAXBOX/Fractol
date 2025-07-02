#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (!lst)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		next = temp -> next;
		del(temp->content);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
