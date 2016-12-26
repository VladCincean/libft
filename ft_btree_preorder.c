#include "libft.h"

void	ft_btree_preorder(t_btree *root, void (*f)(void *, size_t))
{
	if (!root || !f)
		return ;
	f(root->content, root->content_size);
	ft_btree_preorder(root->left, f);
	ft_btree_preorder(root->right, f);
}
