#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last_occurence;

	if (!s)
		return (NULL);
	i = 0;
	last_occurence = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_occurence = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		last_occurence = (char *)&s[i];
	return (last_occurence);
}
