#include "libft.h"
#include <stdlib.h>

static size_t	get_nr_of_words(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	if (*s == '\0')
		return (0);
	ret = 0;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			ret++;
		i++;
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	nr_words;
	char	**ret;
	char	*s1;

	nr_words = get_nr_of_words(s, c);
	ret = (char **)malloc(sizeof(char *) * (nr_words + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		s1 = ft_strchr(s, c);
		ret[i++] = ft_strsub(s, 0, s1 - s);
		while (*s1 == c)
			s1++;
		s = s1;
	}
	ret[i] = 0;
	return (ret);
}
