#include "libft.h"
#include <stdlib.h>

#include <stdio.h> // TODO: delete this

static size_t	get_nr_of_words(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	if (*s == '\0')
		return (0);
	ret = 0;
	if (*s != c)
		ret = 1;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			ret++;
		i++;
	}
	return (ret);
}

static char		*get_next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static size_t	wordlen(char const *s, char c)
{
	size_t	l;

	l = 0;
	while (*s && *s != c)
	{
		l++;
		s++;
	}
	return (l);
}

static void		clean_up(char **ret, size_t i)
{
	while (i-- > 0)
		ft_strdel(&ret[i]);
	ft_strdel(ret);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	nr_words;
	char	**ret;
//	char	*s1;

	nr_words = get_nr_of_words(s, c);
//	printf("nr words = %lu\n", nr_words);
	ret = (char **)ft_memalloc(sizeof(char *) * (nr_words + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < nr_words)
	{
		s = get_next_word(s, c);
		ret[i++] = ft_strsub(s, 0, wordlen(s, c));
		if (ret[i - 1] == NULL)
		{
			clean_up(ret, i);
			return (NULL);
		}
//		printf("-- i = %lu\n", i);
//		printf("%s\n", ret[i - 1]);
		s += wordlen(s, c);
	}
//	printf("i = %lu\n", i);
	ret[nr_words] = 0;
//	ret[nr_words] = ft_strnew(0);
	return (ret);
}
