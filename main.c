#include <string.h>
#include "libft.h"
#include <stdio.h>
#define I 500

int	main(void)
{
	char *s1 = "abcdefg";
	char *s2 = "abcdEfg";

	printf("%d\n", strncmp(s1, s2, I));
	printf("%d\n", ft_strncmp(s1, s2, I));
	return (0);
}
