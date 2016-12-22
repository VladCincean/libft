#include "libft.h"
//#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef union	u_vector_10_int
{
	int		in[10];
	char	ch[40];
}				t_vector_10_int;

int	test_ft_memset()
{
	t_vector_10_int	x;
	int				i;

	for (i = 0; i < 10; i++)
		x.in[i] = 714 * i * i;
	ft_memset((void *)x.in, 0x2a, sizeof(int) * 9);
	if (x.in[9] != 714 * 81)
		return (0);
	for (i = 0; i < 9; i++)
	{
		if (x.ch[i] != 0x2a)
			return (0);
	}
	return (1);
}

int	test_ft_bzero()
{
	t_vector_10_int	x;
	int				i;

	for (i = 0; i < 10; i++)
		x.in[i] = 714 * i * i;
	ft_bzero((void *)x.in, sizeof(int) * 9);
	if (x.in[9] != 714 * 81)
		return (0);
	for (i = 0; i < 9; i++)
	{
		if (x.ch[i] != 0x0)
			return (0);
	}
	return (1);
}

int	test_ft_memcpy()
{
	char	*a;
	char	*b;

	a = (char *)malloc(10);
	b = (char *)malloc(10);
	bzero(a, 10);
	bzero(b, 10);
	a = strcpy(a, "salut!");
	b = ft_memcpy(b, a, 10);
	if (strncmp(a, b, 10) != 0)
	{
		free(a);
		free(b);
		return (0);
	}
	free(a);
	free(b);
	return (1);
}

int	test_ft_memccpy()
{
	char	*a;
	char	*b;
	char	*ptr;

	a = (char *)malloc(10);
	b = (char *)malloc(10);
	bzero(a, 10);
	bzero(b, 10);
	a = strcpy(a, "salut!");
	ptr = ft_memccpy(b, a, 't', 10);
	if (strncmp(a, b, 5) != 0 || strncmp(a, b, 6) == 0 || ptr != b + 5)
	{
		free(a);
		free(b);
		return (0);
	}
	free(a);
	free(b);
	return (1);
}

int	test_ft_memmove()
{
	char	*a;
	char	*ptr;

	a = (char *)malloc(10);
	bzero(a, 10);
	a = strcpy(a, "ABCDEF");
	ptr = ft_memmove(a + 2, a, 10);
	if (strncmp(a, "ABABCDEF", 10) != 0)
	{
		free(a);
		return (0);
	}
	free(a);
	return (1);
}

int	test_ft_memchr()
{
	char	x[10];
	char	*ptr1;
	char	*ptr2;

	bzero(x, 10);
	strcpy(x, "salut!");
	ptr1 = ft_memchr(x, 'l', 10);
	ptr2 = ft_memchr(x, '5', 10);
	if (ptr1 != x + 2 || ptr2 != NULL)
		return (0);
	return (1);
}

int	test_ft_memcmp()
{
	int	a[10];
	int	b[10];
	int	i;

	srand((unsigned int)time(NULL));
	for (i = 0; i < 10; i++)
	{
		a[i] = rand();
		b[i] = rand();
	}
	if (ft_memcmp(a, b, sizeof(int) * 10) != memcmp(a, b, sizeof(int) * 10))
		return (0);
	return (1);
}

int	test_ft_strlen()
{
	char	a[10];
	char	b[15];
	char	c[20];

	strcpy(a, "abcdef");
	strcpy(b, "academy+plus");
	strcpy(c, "hello\0hello");
	if (ft_strlen(a) != strlen(a) ||
			ft_strlen(b) != strlen(b) ||
			ft_strlen(c) != strlen(c))
		return (0);
	return (1);
}

int	test_ft_strdup()
{
	char	*a;
	char	*b;

	a = (char *)malloc(10);
	bzero(a, 10);
	a = strcpy(a, "salut");
	b = ft_strdup(a);
	if (a == b || strncmp(a, b, 10) != 0)
	{
		if (a == b)
			free(b);
		else
		{
			free(a);
			free(b);
		}
		return (0);
	}
	return (1);
}

int	test_ft_strcpy()
{
	char	*a;
	char	*b;

	a = (char *)malloc(10);
	b = (char *)malloc(10);
	a = strcpy(a, "salut");
	b = ft_strcpy(b, a);
	if (strncmp(a, b, 10) != 0)
	{
		free(a);
		free(b);
		return (0);
	}
	free(a);
	free(b);
	return (1);
}

int	test_ft_strncpy()
{
	char	*a;
	char	*b;

	a = (char *)malloc(10);
	b = (char *)malloc(10);
	a = strcpy(a, "salut");
	b = ft_strncpy(b, a, 3);
	if (strncmp(a, b, 3) != 0 || strncmp(a, b, 4) == 0)
	{
		free(a);
		free(b);
		return (0);
	}
	free(a);
	free(b);
	return (1);
}

int	test_ft_strcat()
{
	char	*a;
	int		res;

	a = (char *)malloc(10);
	bzero(a, 10);
	a = ft_strcat(a, "a");
	a = ft_strcat(a, "b");
	a = ft_strcat(a, "c");
	a = ft_strcat(a, "42");
	a = ft_strcat(a, "+++");
	res = strncmp(a, "abc42+++", 10);
	free(a);
	if (res != 0)
		return (0);
	return (1);
}

int	test_ft_strncat()
{
	char	*a;
	int		res;

	a = (char *)malloc(10);
	bzero(a, 10);
	a = ft_strncat(a, "a42", 1);
	a = ft_strncat(a, "bbbbbbbbbbbb", 1);
	a = ft_strncat(a, "cristi", 1);
	a = ft_strncat(a, "424242", 2);
	a = ft_strncat(a, "+++000---", 3);
	res = strncmp(a, "abc42+++", 10);
	free(a);
	if (res != 0)
		return (0);
	return (1);
}

int	test_ft_strlcat()
{
	char		*a;

	a = (char *)malloc(10);
	bzero(a, 10);
	if (ft_strlcat(a, "abc", 1) != 1 ||
			ft_strlcat(a, "bcd", 1) != 2 ||
			ft_strlcat(a, "cde", 1) != 3 ||
			ft_strlcat(a, "424242", 2) != 5 ||
			ft_strlcat(a, "++++++", 3) != 8 ||
			strncmp(a, "abc42+++", 10) != 0)
	{
		free(a);
		return (0);
	}
	free(a);
	return (1);
}

int	main(void)
{
	printf("ft_memset: %d\n", test_ft_memset());
	printf("ft_bzero: %d\n", test_ft_bzero());
	printf("ft_memcpy: %d\n", test_ft_memcpy());
	printf("ft_memccpy: %d\n", test_ft_memccpy());
	printf("ft_memmove: %d\n", test_ft_memmove());
	printf("ft_memchr: %d\n", test_ft_memchr());
	printf("ft_memcmp: %d\n", test_ft_memcmp());
	printf("ft_strlen: %d\n", test_ft_strlen());
	printf("ft_strdup: %d\n", test_ft_strdup());
	printf("ft_strcpy: %d\n", test_ft_strcpy());
	printf("ft_strncpy: %d\n", test_ft_strncpy());
	printf("ft_strcat: %d\n", test_ft_strcat());
	printf("ft_strncat: %d\n", test_ft_strncat());
	printf("ft_strlcat: %d\n", test_ft_strlcat());
	return (0);
}

/* ----------------------------------------------------------------- */
/*
int	test_ft_strsplit()
{
	char	**test;

	test = ft_strsplit("*salut*les***etudiants*", '*');
	printf("%s\n%s\n%s\n%s\n", test[0], test[1], test[2], test[3]);
	assert(strcmp(test[0], "salut") == 0);
	assert(strcmp(test[1], "les") == 0);
	assert(strcmp(test[2], "etudiants") == 0);
	assert(test[3] == 0);
	free(test[0]); free(test[1]); free(test[2]); free(test[3]); free(test);

	test = ft_strsplit("A B C", ' ');
	printf("%s\n%s\n%s\n%s\n", test[0], test[1], test[2], test[3]);
	assert(strcmp(test[0], "A") == 0);
	assert(strcmp(test[1], "B") == 0);
	assert(strcmp(test[2], "C") == 0);
	assert(test[3] == 0);
	free(test[0]); free(test[1]); free(test[2]); free(test[3]); free(test);

	test = ft_strsplit("", ' ');
//	printf("%s\n%s\n%s\n%s\n", test[0], test[1], test[2], test[3]);
	assert(test[0] == 0);
	free(test[0]); free(test);
	return (1);
}

int	test_ft_strncmp()
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	size_t	n;

	s1 = "salut";
	s2 = "salut!";
	s3 = "saABCDEFG";
	s4 = "saABCDEF G";
	for (n = 0; n < 10; n++)
	{
		assert(strncmp(s1, s2, n) == ft_strncmp(s1, s2, n));
		assert(strncmp(s3, s4, n) == ft_strncmp(s3, s4, n));
		assert(strncmp(s1, s3, n) == ft_strncmp(s1, s3, n));
		assert(strncmp(s1, s2, n) == ft_strncmp(s1, s2, n));
//		assert(strncmp(NULL, s1, n) == ft_strncmp(NULL, s1, n));
//		assert(strncmp(s1, NULL, n) == ft_strncmp(s1, NULL, n));
	}
//	assert(strncmp(NULL, NULL, 42) == ft_strncmp(NULL, NULL, 42));
	return (1);
}

int	test_ft_strnequ()
{
	char	*s1 = "ABCDEF";
	char	*s2 = "ABCDeF";

	assert(ft_strnequ(s1, s2, 0) == 1);
	assert(ft_strnequ(s1, s2, 1) == 1);
	assert(ft_strnequ(s1, s2, 2) == 1);
	assert(ft_strnequ(s1, s2, 3) == 1);
	assert(ft_strnequ(s1, s2, 4) == 1);
	assert(ft_strnequ(s1, s2, 5) == 0);
	assert(ft_strnequ(s1, s2, 6) == 0);
	assert(ft_strnequ(s1, s2, 7) == 0);
	return (1);
}

int	test_ft_strequ()
{	
	char	*s1 = "ABCDEF";
	char	*s2 = "ABCDeF";

	assert(ft_strequ(s1, s2) == 0);
	assert(ft_strequ(s1, s1) == 1);
	assert(ft_strequ(s2, s2) == 1);
	return (1);
}

int	main(void)
{
	test_ft_strncmp();
	test_ft_strnequ();
	test_ft_strequ();
	test_ft_strsplit();
	printf("SUCCES!");
	return (0);
}
*/
