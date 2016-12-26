#include "libft.h"

void	ft_btree_insert(t_btree **root, void *content, size_t content_size,
			int (*cmpf)(void *, size_t, void *, size_t))
{
	static size_t	height = 1;

	if (*root == NULL)
	{
		*root = ft_btree_new(content, content_size);
		(*root)->height = height;
	}
	else if (cmpf((*root)->content, (*root)->content_size,
				content, content_size) < 0)
	{
		height++;
		ft_btree_insert(&((*root)->left), content, content_size, cmpf);
	}
	else
	{
		height++;
		ft_btree_insert(&((*root)->right), content, content_size, cmpf);
	}
}
