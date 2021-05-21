#include "get_next_line.h"

int find_n(char *buf, char **line, s_list list)
{
    char *is_n;
    chr *tmp;

    is_n = ft_strch(buf, '\n');
    if (is_n)
    {
        tmp = *line;
        is_n[0] = '\0';
        *line = ft_strjoin(*line, buf);
        free(tmp);
        tmp = list->memory;
        free(list->memory);//????
        list->memory = ft_strdup(is_n + 1);
        free(tmp);
        tmp = NULL;
        return (1)
    }
    *line = ft_strjoin(*line, buf);
    return (0);
}

int clear(char *buf, char **line, int tag)
{
    if (tag == 1)
    {
        free(*buf);
        *buf = NULL;
        free(*line);
        *line = NULL;
        return (-1);
    }
    free(*buf);
    *buf = NULL;
    return (0);
}

int get_next_line(int fd, char **line)
{
    int bytes;
    static  s_list  list;
    char    *tmp[1];
    char *buf[BUFFER_SIZE + 1];

    if (fd < 0 || !line || !(list->memory) || (read(fd, tmp, 0) < 0) \
        || BUFFER_SIZE < 1)
        return (-1);
    *line = ft_strdup("\0");
    if (!*line)
        return (-1);
    while (*list->memory)
    /*{
        if (find_n(buf, *line, list) = 1)
            return (1);
        tmp = *line;
        *line = ft_strjoin(*line, list->memory);
    }*/
    {
        if (find_n(buf, *line, list) = 1)
            return (p == 1 ? 1 : clean(buf, *line, 1));
        free(*list->memory);
    }
    while (read(fd, buf, BUFFER_SIZE) >= 0)
    {
        bytes = ft_strlen(buf);
        buf[bytes] = '\0';
        if (find_n(buf, *line, list) = 1)
            return (1);
    }
        if(*line)
            return (1);
        return (clean(buf, *line, 0));        
    }
}