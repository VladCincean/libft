#ifndef LIBFT_H
# define LIBFT_H

/*
 ** Part I
 */

// memset
// bzero
// memcpy
// memccpy
// memmove
// memchr
// memcmp
// strlen
// strdup
// strcpy
// strncpy
// strcat
// strncat
// strlcat
// strchr
// strrchr
// strstr
// strnstr
// strcmp
// atoi
// isaplha
// isdigit
// isalnum
// isascii
// isprint
// toupper
// tolower

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
void	ft_lstiter(t_list *lst, void (*f)(t_lsit *elem)); // tbd
t_list	*ft_lstmsp(t_list *lst, t_list * (*f)(t_list *elem)); // tbd

/*
 ** Other functions
 */

// ... maybe ...
#endif
