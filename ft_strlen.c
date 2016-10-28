#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (s[i++])
		len++;
	return (len);
}
