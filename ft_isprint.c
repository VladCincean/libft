#include "libft.h"

int	ft_isprint(int c)
{
	if (0x20 <= c && c <= 0x7F)
		return (c);
	return (0);
}
