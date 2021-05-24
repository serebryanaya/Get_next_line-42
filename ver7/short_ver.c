


int get_next_line(int fd, char **line)
{
    
    static  s_list  *list;
    char    *tmp[1];
    char buf[BUFFER_SIZE + 1];
    int ostatok;
    int read_it;

if (fd < 0 || !(line || list_check(fd, list, line) == NULL \
    || (read(fd, tmp, 0) != 0) || BUFFER_SIZE < 1)
        return (-1);

*line = ft_strdup("\0"); // leaks!

ostatok = check_in_memory(line, buf, list->memory);
if (ostatok = 1)
    return (1);
else if (ostatok = -1)
    return (-1);
read_it = ft_read(line, buf, list->memory, fd);
return (read_it);
}