#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ret;

	if (!s || !f)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = f(s[i]);
		i++;
	}
	return (ret);
}
