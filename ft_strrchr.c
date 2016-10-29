#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*last_occurence;

	i = 0;
	last_occurence = NULL;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
			last_occurence = (char *)&s[i];
		i++;
	}
	if (s[i] == ch)
		last_occurence = (char *)&s[i];
	return (last_occurence);
}
