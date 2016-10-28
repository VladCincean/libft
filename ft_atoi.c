#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		ret;
	int		sign;
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	ret = 0;
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
		ret = ret * 10 + str[i++] - '0';
	return (ret * sign);
}
