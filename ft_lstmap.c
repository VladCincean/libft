#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*node;
	t_list	*next;

	if (!lst || !f)
		return (NULL);
	node = f(lst);
	ret = node;
	lst = lst->next;
	while (lst)
	{
		next = f(lst);
		node->next = next;
		node = next;
		lst = lst->next;
	}
	node->next = NULL;
	return (ret);
}
