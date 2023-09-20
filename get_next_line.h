/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:22:01 by pabertha          #+#    #+#             */
/*   Updated: 2023/09/20 13:22:02 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
char				*ft_strjoin(char *s1, char *s2);
char				*free_reset_return(char *to_reset, char *reset_to, char *to_return);
void				update_all(char *buffer, char *line);

#endif
