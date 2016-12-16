#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;
	unsigned char	*temp;
	size_t			i;

	if (!dest || !src)
		return (dest);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	temp = (unsigned char *)malloc(n);
	i = 0;
	while (i < n)
	{
		temp[i] = char_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		char_dest[i] = temp[i];
		i++;
	}
	free(temp);
	return (dest);
}
