/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:20:12 by jpedro-s          #+#    #+#             */
/*   Updated: 2022/05/15 02:01:40 by jpedro-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define MAX_LONG_INT 4294967296
# define HEX "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalpha(int arg);
int		ft_isalnum(int arg);
int		ft_isdigit(int arg);
int		ft_isascii(int arg);
int		ft_isprint(int arg);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_base_converter(unsigned long int nbr, char *base);
char	*ft_uitoa(unsigned int n);
char	*get_next_line(int fd);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
int		ft_printf(const char *format, ...);
int		ft_type_c(int chr);
int		ft_type_s(char *str);
int		ft_type_p(unsigned long int ptr);
int		ft_type_diu(int nbr, char type);
int		ft_type_x(unsigned int to_hex, char type);

#endif
