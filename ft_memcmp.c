#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i < n && ptr1[i] == ptr2[i])
		i++;
	if (i < n)
		return ((int)ptr1[i] - (int)ptr2[i]);
	return (0);
}
