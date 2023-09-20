/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:21:48 by pabertha          #+#    #+#             */
/*   Updated: 2023/09/20 13:37:08 by pabertha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	int		i;

	i = 0;
	if ((dst == NULL && src == NULL) || (dst == NULL && size == 0))
		return (0);
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (d >= size)
		return (size + s);
	while (src[i] != '\0' && ((d + i) < size - 1))
	{
		dst[d + i] = src[i];
		i++;
	}
	if ((d + i) < size)
		dst[d + i] = '\0';
	return (d + s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*s;
	size_t			i;
	unsigned char	*ptr;

	i = nmemb * size;
	if (size != 0 && nmemb > (SIZE_MAX / size))
		return (NULL);
	if (size == 0 || i == 0)
		s = malloc(1);
	else
		s = malloc(i);
	if (s == NULL)
		return (NULL);
	ptr = (unsigned char *)s;
	while (i > 0)
	{
		*ptr = 0;
		ptr++;
		i--;
	}
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i1;
	size_t	i2;
	char	*s3;
	char	*ptr_1;
	char	*ptr_3;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	s3 = ft_calloc(i1 + i2 + 1, 1);
	if (s3 == NULL)
		return (NULL);
	ptr_1 = s1;
	ptr_3 = s3;
	while (s1 != NULL && *s1 != '\0')
		*ptr_3++ = *s1++;
	while (s2 != NULL && *s2 != '\0')
		*ptr_3++ = *s2++;
	return (free_reset_return(ptr_1, NULL, s3));
}
