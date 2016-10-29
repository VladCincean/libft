#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		ret;
	int		sign;
	size_t	i;

	if (!nptr)
		return (0);
	i = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	ret = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
		ret = ret * 10 + nptr[i++] - '0';
	return (ret * sign);
}
