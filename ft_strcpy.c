#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	if (!dest || !src)
		return (dest);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
