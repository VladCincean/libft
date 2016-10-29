#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = (void *)malloc(size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
