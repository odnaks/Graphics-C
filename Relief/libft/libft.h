/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:50:43 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/13 20:43:33 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>

typedef	struct	s_bufs
{
	int			fd;
	char		*buf;
}				t_bufs;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

enum	e_color
{
	RB_BLACK = 0,
	RB_RED = 1
};

typedef struct	s_rbtree
{
	void			*content;
	size_t			content_size;
	struct s_rbtree *parent;
	struct s_rbtree *left;
	struct s_rbtree *right;
	enum e_color	color;
}				t_rbtree;

# define BUFF_SIZE 1024

# define LEFT -1
# define RIGHT 1
# define PREFIX -1
# define INFIX 0
# define POSTFIX 1
# define MEMSWAP_SIZE 32

# define P(x) (x->parent)
# define GRAND(node) node->parent->parent
# define UNCLE(x) (GRAND(x)->left == P(x)) ? GRAND(x)->right : GRAND(x)->left
# define SIBLING(x) ((P(x)->left == x) ? P(x)->right : P(x)->left)
# define SR(node) (SIBLING((*node))->right)
# define SL(node) (SIBLING((*node))->left)

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *str, const char *sub);
char			*ft_strnstr(const char *str, const char *sub, size_t n);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_putwchar(wchar_t c);
void			ft_putwchar_fd(wchar_t c, int fd);
void			ft_putwstr(wchar_t *str);
void			ft_putwstr_fd(wchar_t *str, int fd);
void 			ft_strup(char *str);
int 			ft_isstrdigits(char *str);
int 			ft_isstrdigitsn(char *str, size_t n);

int				ft_memequ(void *m1, void *m2, size_t size);
void			ft_memswap(void *m1, void *m2, size_t size);
t_list			*ft_lstcfind(t_list *lst, void *content, size_t content_size,
					int (*equ)(t_list *e1, t_list *e2));
void			ft_lstradd(t_list **alst, t_list *new);
int				ft_lstcindexof(t_list *lst, void *content, size_t content_size,
					int (*equ)(t_list *e1, t_list *e2));
t_list			*ft_lstfind(t_list *lst, t_list *elem,
					int (*equ)(t_list *e1, t_list *e2));
t_list			*ft_lstindex(t_list *lst, int index);
int				ft_lstindexof(t_list *lst, t_list *elem,
					int (*equ)(t_list *e1, t_list *e2));
int				ft_lstlen(t_list *lst);

void			ft_rbtadd(t_rbtree **root, t_rbtree *new);
void			ft_rbtclr(t_rbtree **node, void (*del)(t_rbtree *elem));
t_rbtree		*ft_rbtfind(t_rbtree *root, t_rbtree *elem,
					int (*cmp)(t_rbtree *elem1, t_rbtree *elem2));
size_t			ft_rbtlen(t_rbtree *root);
t_rbtree		*ft_rbtnew(void const *content, size_t content_size);
t_rbtree		*ft_rbtnew0(void const *content, size_t content_size);
void			ft_rbtrmv(t_rbtree **elem);
size_t			ft_rbtsize(t_rbtree *root);
t_rbtree		*ft_rbtroot(t_rbtree *elem);
void			ft_rbtforeach(t_rbtree *root,
					void (*f)(t_rbtree *elem), int order);
int				ft_rbtcmp(t_rbtree *elem1, t_rbtree *elem2);

int				ft_gnl(const int fd, char **line);
#endif
