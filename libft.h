#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

/*
 ** Part I
 */

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
// strlcat
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle); // tbd
// strnstr
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_isaplha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
 ** Part II
 */

void	*ft_memalloc(size_t size); // tbd
void	ft_memdel(void **ap); // tbd
char	*ft_strnew(size_t size); // tbd
void	ft_strdel(char **as); // tbd
void	ft_strclr(char *s); // tbd
void	ft_striter(char *s, void (*f)(char *)); // tbd
void	ft_striteri(char *s, void (*f)(unsigned int, char *)); // tbd
char	*ft_strmap(char const *s, char (*f)(char)); // tbd
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); // tbd
int		ft_strequ(char const *s1, char const *s2); // tbd
int		ft_strnequ(char const *s1, char const *s2, size_t n); // tbd
char	*ft_strsub(char const *s, unsigned int start, size_t len); // tbd
char	*ft_strjoin(char const *s1, char const *s2); // tbd
char	*ft_strtrim(char const *s); // tbd
char	**ft_strsplit(char const *s, char c); // tbd
char	*ft_itoa(int n); // tbd
void	ft_putchar(char c); // tbd
void	ft_putstr(char const *s); // tbd
void	ft_putendl(char const *s); // tbd
void	ft_putnbr(int n); // tbd
void	ft_putchar_fd(char c, int fd); // tbd
void	ft_putstr_fd(char const *s, int fd); // tbd
void	ft_putendl_fd(char const *s, int fd); // tbd
void	ft_putnbr_fd(int n, int fd); // tbd

/*
 ** Bonus
 */

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(void const *content, size_t content_size); // tbd
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t)); // tbd
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t)); // tbd
void	ft_lstadd(t_list **alst, t_list *new); // tbd
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem)); // tbd
t_list	*ft_lstmsp(t_list *lst, t_list * (*f)(t_list *elem)); // tbd

/*
 ** Other functions
 */

int	ft_islower(int c);
int	ft_isupper(int c);
int	ft_isblank(int c);
int	ft_isspace(int c);
int	ft_isxdigit(int c);
#endif
