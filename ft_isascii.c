#include "libft.h"

int	ft_isascii(int c)
{
	if (0x0 <= c && c <= 0x7F)
		return (1);
	return (0);
}
