#include "libft.h"
#include <stdlib.h>

void	*ft_memdup(const void *src, size_t n)
{
	void	*ret;

	if (!src)
		return (NULL);
	ret = (void *)malloc(n);
	if (!ret)
		return (NULL);
	ret = ft_memcpy(ret, src, n);
	return (ret);
}
