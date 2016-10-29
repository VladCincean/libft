#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*ret;

	if (!s)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	ret = ft_strcpy(ret, s);
	return (ret);
}
