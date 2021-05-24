#include "get_next_line.h"

/*size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *find_n (char *str)
{
    char *ost;
    char *tmp;
    char *now_n;

    if (str == NULL)
        return (0);
    now_n = ft_strchr(str, '\n');
    if (now_n != NULL)
    {
        ost = ft_substr(str, 0, now_n - str);
        printf("25 new_mem = %s\n", ost); //FIXME
         printf("26 ostatok = %s\n", str); //FIXME
         printf("27 now_n - ostatok = %ld\n", (now_n - str)); //FIXME
        tmp = ft_substr(str, now_n - str + 1, ft_strlen(now_n));
         printf("29 tmp = %s\n", tmp); //FIXME
         printf("30 ostatok = %s\n", str); //FIXME
        ft_myzero(str);
         printf("32 ostatok = %s\n", str); //FIXME
        ft_strlcat(str, tmp);
        printf("34 ostatok = %s\n", str); //FIXME
        printf("35 tmp = %s\n", tmp); //FIXME
        free(tmp);
        tmp = NULL;
    }
    else
    {
        ost = malloc((ft_strlen(str) + 1) * sizeof(char));
                printf("42 ost = %s\n", ost); //FIXME
        ost[0] = '\0';
                        printf("44 ost = %s\n", ost); //FIXME
        ft_strlcat(ost, str);
        printf("46 ost = %s\n", ost); //FIXME
        printf("47 str = %s\n", str); //FIXME
        ft_myzero(str);
                printf("49 str = %s\n", str); //FIXME
    }
    return (ost);
}

int get_next_line(int fd, char **line)
{
    static char *ostatok;
    char *is_n;
    char buffer[BUFFER_SIZE + 1];
    //char *copy_line;
    int bytes;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
     if (ostatok != NULL)
        ostatok = find_n(ostatok);
    while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes] = '\0';
        printf("70: buffer = %s\n", buffer); //FIXME
        //printf("str 67: is_n = %s\n", is_n); //FIXME
        if (!(is_n = ft_strchr(buffer, '\n')))
             {
                 printf("str 70: is_n = %s\n", is_n); //FIXME
                 printf("str 72: line = %s\n", *line); //FIXME
            *line = ft_strjoin(*line, buffer);
                             printf("str 72: line = %s\n", *line); //FIXME
             }
        else
        {
            is_n[0] = '\0';
                    printf("str 77: is_n = %s\n", is_n); //FIXME
            *line = ft_strjoin(*line, ft_substr(buffer, 0, (is_n - buffer + 1)));
                          printf("str 79: line = %s\n", *line); //FIXME
            ostatok = ft_substr(buffer, (is_n - buffer + 1), ft_strlen(is_n + 1));
                        printf("str 81: ostatok = %s\n", ostatok); //FIXME
            find_n(ostatok);
            return(1);
        }
    }
    is_n = NULL;
    printf("line = %s\n", *line); //FIXME
    printf("ostatok = %s\n", ostatok); //FIXME
    if (ostatok == NULL)
        printf("ostatok = %s\n", ostatok); //FIXME
    *line = search_ostatok(ostatok);
                 printf("ostatok before = %s\n", ostatok); //FIXME
        if (line)
        {
             printf("ostatok = %s\n", ostatok); //FIXME
             return (1);           
        }

    while (is_n == NULL && (bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes] = '\0';
        printf("buffer = %s\n", buffer); //FIXME
        printf("is_n = %s\n", is_n); //FIXME
        if ((is_n = ft_strchr(buffer, '\n')) != NULL)
            {
                printf("is_n = %s\n", is_n); //FIXME
                ostatok = malloc(sizeof(char) * ft_strlen(is_n));
                        printf("ostatok = %s\n", ostatok); //FIXME
                ostatok[0] = '\0';
                ft_strlcat(ostatok, ++is_n);
                printf("ostatok = %s\n", ostatok); //FIXME
                printf("is_n) = %s\n", is_n); //FIXME
                ft_myzero(--is_n);
            }
        copy_line = *line;
        *line = ft_strjoin(copy_line, buffer);
        if (!line || bytes < 0)
            return (-1);
        free(copy_line);
        copy_line = NULL;
    }
    if (ft_strlen(*line) != 0 || ft_strlen(ostatok) != 0 || bytes > 0)
        return (1);
    return (0);
}*/
/*
size_t	ft_strlen(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_strdel(char **as)
{
	ft_memdel((void**)as);
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size > 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (0);
}

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*res;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	res = str;
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (res);
}
char	*ft_strcat(char *restrict str1, const char *restrict str2)
{
	char *tmp;

	tmp = str1;
	while (*str1)
		str1++;
	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (tmp);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	i = 0;
	sub_str = (char *)malloc(len + 1);
	if (sub_str == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

t_arr		*newlist(const int fd)
{
	t_arr	*new;

	if (!(new = (t_arr *)malloc(sizeof(t_arr))))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

char		*checkrest(char **p_n, char *rest)
{
	char *str;

	if ((*p_n = ft_strchr(rest, '\n')) != NULL)
	{
		str = ft_strsub(rest, 0, *p_n - rest);
		ft_strcpy(rest, ++(*p_n));
	}
	else
	{
		str = ft_strnew(ft_strlen(rest) + 1);
		ft_strcat(str, rest);
		ft_strclr(rest);
	}
	return (str);
}

int			get_line(const int fd, char **line, char *rest)
{
	char			buf[BUFF_SIZE + 1];
	char			*p_n;
	char			*tmp;
	int				rd;

	p_n = NULL;
	rd = 1;
	*line = checkrest(&p_n, rest);
	while (p_n == 0 && ((rd = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[rd] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(rest, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || rd < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(rest) || rd) ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static t_arr	*list;
	t_arr			*tmp;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	if (!list)
		list = newlist(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = newlist(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->rest);
	return (ret);
}*/

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char		*join_str(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*rtn;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return (0);
	ft_memmove(rtn, s1, s1_len);
	ft_memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	free((char *)s1);
	return (rtn);
}

int			has_return(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(rtn = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save;
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!has_return(save) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		save = join_str(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (0);
	return (1);
}