#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	dest_len = ft_strlen(dest);
	i = 0;
	while (i < n && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[dest_len + i] = '\0';
		i++;
	}
	return (ft_strlen(dest));
}
