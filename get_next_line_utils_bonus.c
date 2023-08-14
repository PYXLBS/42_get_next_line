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
	while (s[i] != '\0')
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	size_t	i2;
	char	*s3;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	s3 = ft_calloc(i1 + i2 + 1, 1);
	if (s3 == NULL)
		return (NULL);
	ptr = s3;
	while (*s1 != '\0')
		*ptr++ = *s1++;
	while (*s2 != '\0')
		*ptr++ = *s2++;
	return (s3);
}
