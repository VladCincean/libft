#include "libft.h"

/*
 ** We use ft_strnew() instead of malloc() in order to initializate
 ** all the chars in the array to '\0'.
 */

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	ret = strncpy(ret, s + start, len);
	return (ret);
}
