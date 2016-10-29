#include "libft.h"

int	ft_isblank(int c)
{
	if (c == ' ' || c == '\t')
		return (c);
	return (0);
}
