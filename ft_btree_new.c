#include "libft.h"
#include <stdlib.h>

t_btree	*ft_btree_new(void const *content, size_t content_size)
{
	t_btree	*ret;

	if(!(ret = (t_btree *)malloc(sizeof(t_btree))))
		return (NULL);
	if (!content)
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	else
	{
		ret->content = ft_memdup(content, content_size);
		ret->content_size = content_size;
	}
	ret->left = NULL;
	ret->right = NULL;
	ret->height = 1;
	return (ret);
}
