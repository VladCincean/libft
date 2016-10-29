#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ret;

	ret = (char*)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
