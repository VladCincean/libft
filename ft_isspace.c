#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' ||
		c == 't' || c == '\v')
		return (c);
	return (0);
}
