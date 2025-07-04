#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*head;
	t_list		*temp;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	ft_lstadd_back(&head, new);
	temp = head;
	lst = lst->next;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			return (ft_lstclear(&head, del), NULL);
		ft_lstadd_back(&temp, new);
		temp = temp->next;
		lst = lst->next;
	}
	return (head);
}
