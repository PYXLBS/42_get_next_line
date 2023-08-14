#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

char				*get_next_line(int fd);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);

#endif
