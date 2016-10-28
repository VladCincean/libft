#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*ret;

	ret = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	ret = ft_strcpy(ret, s);
	return (ret);
}
