


int get_next_line(int fd, char **line)
{
    int bytes;
    static  s_list  *list;
    char    *tmp[1];
    char *buf;

     if (fd < 0 || !line || list_check(fd, &list, line) < 0 || (read(fd, tmp, 0) < 0) \ // в list_check в лайн уже добавили mem
        || BUFFER_SIZE < 1)
        return (-1);

    bytes = 1;
    while (bytes > 0)
    {  
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (clean(list->memory, buf, line, 4)); // 4 - очистка только буфера и line
    bytes = read(fd, buf, BUFFER_SIZE);
    if (bytes = 0)
        {
            clean(list->memory, buf, line, 4);
            return (0);
        }
    buf[bytes] = '\0';
    if (make_line(buf, line, list->memory) == 1) // то есть мы выводили (line + \0). остаток записали в mem
        {
            clean(list->memory, buf, line, 5) // очистка только буфера;
            return (1);
        }
    }
   // return (clean(list->memory, line, 0)); // очищаем только mem, line не трогаем
}

int make_line(char *buf, char **line, char *memory)
{
    char *is_n;
    char *tmp;

    is_n = ft_mystrchr(buf);
    tmp = *line;
    *line = ft_strjoin(*line, buf);
    if (!*line)
        return (-1);
    if (is_n != NULL && (is_n - buf > 0))
        {
            memory = ft_strdup(is_n + 1);
            return (1);
        }
    return(0);
}