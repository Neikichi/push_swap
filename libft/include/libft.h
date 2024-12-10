/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:56:28 by vlow              #+#    #+#             */
/*   Updated: 2024/12/10 13:30:25 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// For header depended libs only.
# include <stddef.h>
# include <stdarg.h>

// get next line buffer
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Linked List
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// for printf control struct
typedef struct s_flags {
	int		left_align;
	int		zero_pad;
	int		hash_hex;
	int		show_sign;
	int		space;
	int		width;
	int		precision;
	char	specifier;
	char	*buffer;
}	t_flags;

// char function
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isspace(int c);

// string function
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
void	ft_strlowercase(char *str);
void	ft_struppercase(char *str);

// Memory function
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// Number or digits function
int		ft_atoi(const char *nptr);
int		ft_countdigits(long int n);
int		ft_countdigits_u(unsigned long int n);
int		ft_countdigits_hex(unsigned long int n);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned long int n);
char	*ft_itoa_hex(unsigned long int n);

// System call I/O
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnstr_fd(char *s, int n, int fd);
void	ft_putnchar_fd(char c, int n, int fd);
char	*get_next_line(int fd);

// List and linked list
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstpop_front(t_list **lst);
void	ft_lstpop_back(t_list **lst);

// printf section
int		ft_printf(const char *format, ...);
int		bs_esc(const char *fptr);
int		fl_set(const char **c, t_flags *flags);
t_flags	fl_init(void);
int		fl_load(va_list vlist, t_flags *flags);
int		fl_sp_c(va_list vlist, t_flags *flags);
int		fl_sp_s(va_list vlist, t_flags *flags);
int		fl_sp_di(va_list vlist, t_flags *flags);
int		fl_sp_u(va_list vlist, t_flags *flags);
int		fl_sp_p(va_list vlist, t_flags *flags);
int		fl_sp_x(va_list vlist, t_flags *flags);

/*
things to add later:-
count words?

*/
#endif
