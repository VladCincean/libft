#include "libft.h"

int	ft_isxdigit(int c)
{
	if (ft_isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F'))
		return (c);
	return (0);
}
