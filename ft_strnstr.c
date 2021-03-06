/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcincean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 14:05:49 by vcincean          #+#    #+#             */
/*   Updated: 2017/02/23 11:10:43 by vcincean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Computes the prefix table array and returns it
** m = len(pattern)
** i = the longest prefix that has been found in the pattern
** j = current index for which pi[j] is currently calculated
** pi = the prefix table array
** pi[j] = the length of the longest proper prefix of pattern
**			that is a proper suffix of pattern[0..j], j = 0..m-1
*/

static int	*kmp_prefix_function(const char *pattern)
{
	int	m;
	int	i;
	int	j;
	int	*pi;

	m = ft_strlen(pattern);
	pi = (int*)malloc(sizeof(int) * m);
	pi[0] = 0;
	i = 0;
	j = 1;
	while (j < m)
	{
		while (i > 0 && pattern[i] != pattern[j])
			i = pi[i - 1];
		if (pattern[i] == pattern[j])
			i++;
		pi[j] = i;
		j++;
	}
	return (pi);
}

/*
** Finds the first occurence of pattern in text
** q = nr. of characters matched
** i = current position
*/

static char	*kmp_matcher(const char *text, const char *pattern, size_t n)
{
	int		m;
	int		*pi;
	size_t	i;
	int		q;

	m = ft_strlen(pattern);
	pi = kmp_prefix_function(pattern);
	i = 0;
	q = 0;
	while (i < n)
	{
		while (q > 0 && pattern[q] != text[i])
			q = pi[q - 1];
		if (pattern[q] == text[i])
			q++;
		if (q == m)
		{
			free(pi);
			return ((char*)text + i - m + 1);
		}
		i++;
	}
	free(pi);
	return (NULL);
}

char		*ft_strnstr(const char *text, const char *pattern, size_t n)
{
	if (*pattern == '\0')
		return ((char*)text);
	if (ft_strlen(text) < n)
		n = ft_strlen(text);
	return (kmp_matcher(text, pattern, n));
}
