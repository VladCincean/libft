#include "libft.h"

void	ft_btree_inorder(t_btree *root, void (*f)(void *, size_t))
{
	if (!root || !f)
		return ;
	ft_btree_inorder(root->left, f);
	f(root->content, root->content_size);
	ft_btree_inorder(root->right, f);
}
