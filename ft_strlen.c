#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	len;
	int	i;

	i = 0;
	while (s[i++])
		len++;
	return (len);
}