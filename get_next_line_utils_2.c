#include "get_next_line.h"

size_t	ft_strlcat(char *dst, char *src)
{
	size_t	i;
	size_t	orig;
	size_t	j;

	j = 0;
	orig = ft_strlen(dst);
	i = orig;
	while (src[j] != '\0')
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ft_strlen(src) + orig);
}

void	*ft_memccpy(void *dst, void *src, char c)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	i = 0;
	while (dst)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == c)
			return (dst + i);
		i++;
	}
	return (NULL);
}

void	ft_myzero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strchr(char *str, char c) // ищет 1е вхождение разделителя в строку
{
	size_t	i;

	i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) != c)
			i++;
		else
			return (str + i);
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}

/*void	ft_strl(char *memory, char *is_n)
{
	int i;

	i = 0;
	while (is_n[i] != '\0')
	{
		memory[i] = is_n[i];
		i++;
 	}
	while (memory[i] != '\0')
	{
		memory[i] = '\0';
		i++;
 	}
}*/

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dstsize > 0)
	{
		while ((src[i] != '\0') && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(char *s1)
{
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, (ft_strlen(s1) + 1));
	return (dup);
}

char	*ft_strjoin (char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char *s, int start_s, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t		start;

	i = 0;
	start = start_s;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(sub = malloc(sizeof(char) * 1)))
			return (NULL);
		sub[i] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char    *ft_calloc(size_t count, size_t size)
{
    char    *dst;
    size_t  i;
    size_t  all;

    all = count * size;
    dst = malloc(all);
    if (dst == 0)
        return (NULL);
    i = 0;
    while (all != 0)
{
    dst[i] = '\0';
    i++;
    all--;
}
return (dst);
}