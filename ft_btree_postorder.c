#include "libft.h"

void	ft_btree_postorder(t_btree *root, void (*f)(void *, size_t))
{
	if (!root || !f)
		return ;
	ft_btree_postorder(root->left, f);
	ft_btree_postorder(root->right, f);
	f(root->content, root->content_size);
}
