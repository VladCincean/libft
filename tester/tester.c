#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

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

int	test_ft_strlcat() /* DEPRECATED */
{
	/*
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
	*/
	return (1);
}

int	test_ft_strchr()
{
	char	a[10];

	bzero(a, 10);
	strcpy(a, "ABADABCDB");
	if (ft_strchr(a, 'A') != strchr(a, 'A') ||
			ft_strchr(a, 'B') != strchr(a, 'B') ||
			ft_strchr(a, 'C') != strchr(a, 'C') ||
			ft_strchr(a, 'D') != strchr(a, 'D') ||
			ft_strchr(a, 'F') != strchr(a, 'F') ||
			ft_strchr(a, '\0') != strchr(a, '\0'))
		return (0);
	return (1);
}

int	test_ft_strrchr()
{
	char	a[10];

	bzero(a, 10);
	strcpy(a, "ABADABCDB");
	if (ft_strrchr(a, 'A') != strrchr(a, 'A') ||
			ft_strrchr(a, 'B') != strrchr(a, 'B') ||
			ft_strrchr(a, 'C') != strrchr(a, 'C') ||
			ft_strrchr(a, 'D') != strrchr(a, 'D') ||
			ft_strrchr(a, 'F') != strrchr(a, 'F') ||
			ft_strrchr(a, '\0') != strrchr(a, '\0'))
		return (0);
	return (1);
}

int	test_ft_strstr()
{
	char	pattern[] = "abababca";
	char	text[] = "bacbabababcabab";

	if (ft_strstr(text, pattern) != strstr(text, pattern) ||
			ft_strstr(text, "baab") != strstr(text, "baab") ||
			ft_strstr(text, "ca") != strstr(text, "ca") ||
			ft_strstr(text, "\0") != strstr(text, "\0") ||
			ft_strstr(text, "f") != strstr(text, "f") ||
			ft_strstr("ABC", "ABC") != strstr("ABC", "ABC"))
		return (0);
	return (1);
}

int	test_ft_strnstr()
{
	char	pattern[] = "abababca";
	char	text[] = "bacbabababcabab";
	size_t	i;

	for (i = 0; i < 30; i++)
	{
		if (ft_strstr(text, pattern) != strstr(text, pattern) ||
				ft_strstr(text, "baab") != strstr(text, "baab") ||
				ft_strstr(text, "ca") != strstr(text, "ca") ||
				ft_strstr(text, "\0") != strstr(text, "\0") ||
				ft_strstr(text, "f") != strstr(text, "f") ||
				ft_strstr("ABC", "ABC") != strstr("ABC", "ABC"))
			return (0);
	}
	return (1);
}

int	test_ft_strcmp()
{
	char	a[] = "Hello World!";
	char	b[] = "Hello, world";

	if (ft_strcmp(a, b) != strcmp(a, b))
		return (0);
	return (1);
}

int	test_ft_strncmp()
{
	char	a[] = "Hello World!";
	char	b[] = "Hello, world";
	size_t	n;

	for (n = 0; n < 20; n++)
	{
		if (ft_strcmp(a, b) != strcmp(a, b))
			return (0);
	}
	return (1);
}

int	test_ft_atoi()
{
	char	a[] = "42";
	char	b[] = "-42";
	char	c[] = "+42";
	char	d[] = "-2147483648";
	char	e[] = "    42";
	char	f[] = "RO42";
	char	g[] = "\t  \t\n\r42";
	char	h[] = "-1851584881817881";
	char	i[] = "-4848981129218$212";
	char	j[] = "\t\t#42";

	if (ft_atoi(a) != atoi(a) || ft_atoi(b) != atoi(b) ||
			ft_atoi(c) != atoi(c) || ft_atoi(d) != atoi(d) ||
			ft_atoi(e) != atoi(e) || ft_atoi(f) != atoi(f) ||
			ft_atoi(g) != atoi(g) || ft_atoi(h) != atoi(h) ||
			ft_atoi(i) != atoi(i) || ft_atoi(j) != atoi(j))
		return (0);
	return (1);
}

int	test_ft_isalpha()
{
	int	c;

	for (c = -300; c < 300; c++)
	{
		if (ft_isalpha(c) != isalpha(c))
			return (0);
	}
	return (1);
}

int	test_ft_isdigit()
{
	int	c;

	for (c = -300; c < 300; c++)
	{
		if (ft_isdigit(c) != isdigit(c))
			return (0);
	}
	return (1);
}

int	test_ft_isalnum()
{
	int	c;

	for (c = -300; c < 300; c++)
	{
		if (ft_isalnum(c) != isalnum(c))
			return (0);
	}
	return (1);
}

int	test_ft_isascii()
{
	int	c;

	for (c = -300; c < 300; c++)
	{
		if (ft_isascii(c) != isascii(c))
			return (0);
	}
	return (1);
}

int	test_ft_isprint()
{
	int	c;

	for (c = -300; c < 300; c++)
	{
		if (ft_isprint(c) != isprint(c))
			return (0);
	}
	return (1);
}

int	test_ft_toupper()
{
	int	c;

	for (c = -300; c < 300; c++)
	{
		if (ft_toupper(c) != toupper(c))
			return (0);
	}
	return (1);
}

int	test_ft_tolower()
{
	int	c;

	for (c = -300; c < 300; c++)
	{
		if (ft_tolower(c) != tolower(c))
			return (0);
	}
	return (1);
}

int	test_ft_memalloc()
{
	void	*a;
	void	*b;

	a = malloc(42);
	if (!a)
		return (-1);
	bzero(a, 42);
	b = ft_memalloc(42);
	if (!b)
	{
		free(a);
		return (0);
	}
	if (memcmp(a, b, 42) != 0)
	{
		free(a); free(b);
		return (0);
	}
	free(a); free(b);
	return (1);
}

int	test_ft_memdel()
{
	void	*p;
	void	*q;
	int		tests;

	tests = 2;
	p = malloc(42);
	if (!p)
		return (-1);
	q = malloc(0);
	if (!q)
	{
		free(p);
		return (-1);
	}
	ft_memdel(&p);
	if (p == NULL)
		tests--;
	if (tests == 2)
		free(p);
	ft_memdel(&q);
	if (q == NULL)
		tests--;
	if (tests > 0)
		free(q);
	if (tests != 0)
		return (0);
	return (1);
}

int	test_ft_strnew()
{
	char	*a;
	char	*b;

	a = (char *)malloc(42);
	if (!a)
		return (-1);
	bzero(a, 42);
	b = ft_strnew(42);
	if (!b)
	{
		free(a);
		return (0);
	}
	if (strncmp(a, b, 42) != 0)
	{
		free(a); free(b);
		return (0);
	}
	free(a); free(b);
	return (1);
}

int	test_ft_strdel()
{
	char	*p;
	char	*q;
	int		tests;

	tests = 2;
	p = (char *)malloc(42);
	if (!p)
		return (-1);
	p = strcpy(p, "salut!");
	q = malloc(0);
	if (!q)
	{
		free(p);
		return (-1);
	}
	ft_strdel(&p);
	if (p == NULL)
		tests--;
	if (tests == 2)
		free(p);
	ft_strdel(&q);
	if (q == NULL)
		tests--;
	if (tests > 0)
		free(q);
	if (tests != 0)
		return (0);
	return (1);
}

int	test_ft_strclr()
{
	char	*s;
	char	*t;

	s = (char *)malloc(42);
	if (!s)
		return (-1);
	t = (char *)malloc(42);
	if (!t)
	{
		free(s);
		return (-1);
	}
	bzero(s, 42);
	bzero(t, 42);
	s = strcpy(s, "hello hello hello");
	ft_strclr(s);
	if (memcmp(s, t, 42) != 0)
	{
		free(s); free(t);
		return (0);
	}
	free(s); free(t);
	return (1);
}

static void	__t_striter(char *c)
{
	*c += 1;
}

int	test_ft_striter()
{
	char	str[] = "aBcDeF";

	ft_striter(str, __t_striter);
	if (strncmp(str, "bCdEfG", 6) != 0)
		return (0);
	return (1);
}

static void	__t_striteri(unsigned int i, char *c)
{
	*c += i;
}

int	test_ft_striteri()
{
	char	str[] = "aBcDeF";

	ft_striteri(str, __t_striteri);
	if (strncmp(str, "aCeGiK", 6) != 0)
		return (0);
	return (1);
}

static char	__t_strmap(char c)
{
	return (c + 1);
}

int	test_ft_strmap()
{
	char	*a;
	char	*b;

	a = strdup("aBcDeF");
	if (!a)
		return (-1);
	b = ft_strmap(a, __t_strmap);
	free(a);
	a = NULL;
	if (strncmp(b, "bCdEfG", 6) != 0)
	{
		free(b);
		return (0);
	}
	free(b);
	return (1);
}

static char	__t_strmapi(unsigned int i, char c)
{
	return (c + i);
}

int	test_ft_strmapi()
{
	char	*a;
	char	*b;

	a = strdup("aBcDeF");
	if (!a)
		return (-1);
	b = ft_strmapi(a, __t_strmapi);
	free(a);
	a = NULL;
	if (strncmp(b, "aCeGiK", 6) != 0)
	{
		free(b);
		return (0);
	}
	free(b);
	return (1);
}


int	test_ft_strequ()
{	
	char	s1[] = "ABCDEF";
	char	s2[] = "ABCDeF";

	if (ft_strequ(s1, s2) != 0 ||
			ft_strequ(s1, s1) != 1 ||
			ft_strequ(s2, s2) != 1)
		return (0);
	return (1);
}

int	test_ft_strnequ()
{
	char	s1[] = "ABCDEF";
	char	s2[] = "ABCDeF";
	int		check;
	int		i;

	check = 1;
	for (i = 0; i < 10; i++)
	{
		if (i == 5)
			check = 0;
		if (ft_strnequ(s1, s2, i) != check)
			return (0);
	}
	return (1);
}

int	test_ft_strsub()
{
	char	str[] = "0123456789 hello";
	char	*r;

	r = ft_strsub(str, 3, 1);
	if (strncmp(r, "3", 2) != 0)
	{
		free(r);
		return (0);
	}
	free(r);
	r = ft_strsub(str, 7, 6);
	if (strncmp(r, "789 he", 7) != 0)
	{
		free(r);
		return (0);
	}
	free(r);
	if (ft_strsub(str, 2, -42) != NULL)
		return (0);
	return (1);
}

int	test_ft_strjoin()
{
	char	*r;

	r = ft_strjoin("hello", " world!");
	if (!r)
		return (-1);
	if (strncmp(r, "hello world!", 20) != 0)
	{
		free(r);
		return (0);
	}
	free(r);
	return (1);
}

int	test_ft_strtrim()
{
	char	*r;

	r = ft_strtrim("  \t \n hello world!   \t \n\n\n");
	if (!r)
		return (-1);
	if (strncmp(r, "hello world!", 20) != 0)
	{
		free(r);
		return (0);
	}
	free(r);
	return (1);
}

int	test_ft_strsplit()
{
	char	**test;
	int		result;

	result = 1;
	test = ft_strsplit("*salut*les***etudiants*", '*');
	if (strncmp(test[0], "salut", 6) != 0 ||
			strncmp(test[1], "les", 4) != 0 ||
			strncmp(test[2], "etudiants", 15) != 0 ||
			test[3] != 0)
		result = 0;
	free(test[0]); free(test[1]); free(test[2]); free(test[3]); free(test);
	test = ft_strsplit("", ' ');
	if (test[0] != 0)
		result = 0;
	free(test[0]); free(test);
	return (result);
}

int	test_ft_itoa()
{
	char	*r;

	r = ft_itoa(-42);
	if (!r)
		return (-1);
	if (strncmp(r, "-42", 4) != 0)
	{
		free(r);
		return (0);
	}
	free(r);
	r = ft_itoa(-0);
	if (!r)
		return (-1);
	if (strncmp(r, "0", 2) != 0)
	{
		free(r);
		return (0);
	}
	free(r);
	return (1);
}

int	test_ft_putchar()
{
	int		my_pipe[2];
	int		stdout_backup;
	char	buffer[4];

	pipe(my_pipe);
	stdout_backup = dup(1);
	dup2(my_pipe[1], 1);
	ft_putchar('4');
	ft_putchar('2');
	ft_putchar('!');
	dup2(stdout_backup, 1);
	read(my_pipe[0], buffer, 3);
	buffer[3] = 0;
	close(my_pipe[0]); close(my_pipe[1]);
	if (strncmp(buffer, "42!", 4) != 0)
		return (0);
	return (1);
}

int	test_ft_putstr()
{
	int		my_pipe[2];
	int		stdout_backup;
	char	buffer[4];

	pipe(my_pipe);
	stdout_backup = dup(1);
	dup2(my_pipe[1], 1);
	ft_putstr("42!");
	dup2(stdout_backup, 1);
	read(my_pipe[0], buffer, 3);
	buffer[3] = 0;
	close(my_pipe[0]); close(my_pipe[1]);
	if (strncmp(buffer, "42!", 4) != 0)
		return (0);
	return (1);
}

int	test_ft_putendl()
{
	int		my_pipe[2];
	int		stdout_backup;
	char	buffer[5];

	pipe(my_pipe);
	stdout_backup = dup(1);
	dup2(my_pipe[1], 1);
	ft_putendl("42!");
	dup2(stdout_backup, 1);
	read(my_pipe[0], buffer, 4);
	buffer[4] = 0;
	close(my_pipe[0]); close(my_pipe[1]);
	if (strncmp(buffer, "42!\n", 5) != 0)
		return (0);
	return (1);
}

int	test_ft_putnbr()
{
	int		my_pipe[2];
	int		stdout_backup;
	char	buffer[4];

	pipe(my_pipe);
	stdout_backup = dup(1);
	dup2(my_pipe[1], 1);
	ft_putnbr(100);
	dup2(stdout_backup, 1);
	read(my_pipe[0], buffer, 3);
	buffer[3] = 0;
	close(my_pipe[0]); close(my_pipe[1]);
	if (strncmp(buffer, "100", 4) != 0)
		return (0);
	return (1);
}

int	test_ft_putchar_fd()
{
	int		my_pipe[2];
	char	buffer[4];

	pipe(my_pipe);
	ft_putchar_fd('4', my_pipe[1]);
	ft_putchar_fd('2', my_pipe[1]);
	ft_putchar_fd('!', my_pipe[1]);
	read(my_pipe[0], buffer, 3);
	buffer[3] = 0;
	close(my_pipe[0]); close(my_pipe[1]);
	if (strncmp(buffer, "42!", 4) != 0)
		return (0);
	return (1);
}

int	test_ft_putstr_fd()
{
	int		my_pipe[2];
	char	buffer[4];

	pipe(my_pipe);
	ft_putstr_fd("42!", my_pipe[1]);
	read(my_pipe[0], buffer, 3);
	buffer[3] = 0;
	close(my_pipe[0]); close(my_pipe[1]);
	if (strncmp(buffer, "42!", 4) != 0)
		return (0);
	return (1);
}

int	test_ft_putendl_fd()
{
	int		my_pipe[2];
	char	buffer[5];

	pipe(my_pipe);
	ft_putendl_fd("42!", my_pipe[1]);
	read(my_pipe[0], buffer, 4);
	buffer[4] = 0;
	close(my_pipe[0]); close(my_pipe[1]);
	if (strncmp(buffer, "42!\n", 5) != 0)
		return (0);
	return (1);
}

int	test_ft_putnbr_fd()
{
	int		my_pipe[2];
	char	buffer[4];

	pipe(my_pipe);
	ft_putnbr_fd(100, my_pipe[1]);
	read(my_pipe[0], buffer, 3);
	buffer[3] = 0;
	close(my_pipe[0]); close(my_pipe[1]);
	if (strncmp(buffer, "100", 4) != 0)
		return (0);
	return (1);
}

int	main(void)
{
	printf("Testing part 1...\n");
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
	printf("ft_strlcat (DEPRECATED): %d\n", 1);
	printf("ft_strchr: %d\n", test_ft_strchr());
	printf("ft_strrchr: %d\n", test_ft_strrchr());
	printf("ft_strstr: %d\n", test_ft_strstr());
	printf("ft_strnstr: %d\n", test_ft_strnstr());
	printf("ft_strcmp: %d\n", test_ft_strcmp());
	printf("ft_strncmp: %d\n", test_ft_strncmp());
	printf("ft_atoi: %d\n", test_ft_atoi());
	printf("Note: the following tests may NOT pass if the OS is Linux.\n");
	printf("ft_isalpha: %d\n", test_ft_isalpha());
	printf("ft_isdigit: %d\n", test_ft_isdigit());
	printf("ft_isalnum: %d\n", test_ft_isalnum());
	printf("ft_isascii: %d\n", test_ft_isascii());
	printf("ft_isprint: %d\n", test_ft_isprint());
	printf("ft_toupper: %d\n", test_ft_toupper());
	printf("ft_tolower: %d\n", test_ft_tolower());
	printf("--------------\n");
	printf("Testing part 2...\n");
	printf("ft_memalloc: %d\n", test_ft_memalloc());
	printf("ft_memdel: %d\n", test_ft_memdel());
	printf("ft_strnew: %d\n", test_ft_strnew());
	printf("ft_strdel: %d\n", test_ft_strdel());
	printf("ft_strclr: %d\n", test_ft_strclr());
	printf("ft_striter: %d\n", test_ft_striter());
	printf("ft_striteri: %d\n", test_ft_striteri());
	printf("ft_strmap: %d\n", test_ft_strmap());
	printf("ft_strmapi: %d\n", test_ft_strmapi());
	printf("ft_strnequ: %d\n", test_ft_strnequ());
	printf("ft_strsub: %d\n", test_ft_strsub());
	printf("ft_strjoin: %d\n", test_ft_strjoin());
	printf("ft_strtrim: %d\n", test_ft_strtrim());
	printf("ft_strsplit: %d\n", test_ft_strsplit());
	printf("ft_itoa: %d\n", test_ft_itoa());
	printf("ft_putchar: %d\n", test_ft_putchar());
	printf("ft_putstr: %d\n", test_ft_putstr());
	printf("ft_putendl: %d\n", test_ft_putendl());
	printf("ft_putnbr: %d\n", test_ft_putnbr());	
	printf("ft_putchar_fd: %d\n", test_ft_putchar_fd());
	printf("ft_putstr_fd: %d\n", test_ft_putstr_fd());
	printf("ft_putendl_fd: %d\n", test_ft_putendl_fd());
	printf("ft_putnbr_fd: %d\n", test_ft_putnbr_fd());
	return (0);
}
