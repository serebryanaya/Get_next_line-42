


int get_next_line(int fd, char **line)
{
    
    static  s_list  *list;
    char    *tmp[1];
    char buf[BUFFER_SIZE + 1];
    int ostatok;
    int read_it;
    s_list *current_list;

ostatok = 0;

*line = ft_strdup("\0");

if (fd < 0 || !line  || !(*line) || (read(fd, tmp, 0) != 0) || BUFFER_SIZE < 1)
    return (-1);

if (!list)
    {
        list = create_list(fd); // may NULL will return. so need to do return -1
        if (list == NULL)
            return (-1);
    }

current_list = list_check(fd, list);
if (!current_list)
    return (-1);

if (current_list->len > 0)
    {
        ostatok = check_in_memory(line, buf, current_list);
        if (ostatok = 1)
            {
                free(current_list);
                return (1);
            }
        else if (ostatok = -1)
                return (-1);
    }
else
    read_it = ft_read(line, buf, current_list, fd);
return (read_it);
}



int ft_read(char **line, char *buf, s_list *list, int fd)
{
int bytes;
char *is_n;

bytes = 1;
while (bytes > 0)
{  
buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));

if (!buf)
    return (-1);

bytes = read(fd, buf, BUFFER_SIZE);

if (bytes == 0)
        return (1 + clean(list, buf, line, 5));

is_n = ft_strchr(buf);

if (is_n != NULL && (is_n - buf + 1 != ft_strlen(buf)))
       {
        list->memory = ft_strdup(is_n + 1);
        if (!list->memory)
            return (-1);
        is_n[0] = '\0';
        *line = ft_strjoin(*line, buf);
        return (2 + clean(list, buf, line, 5)); // clean buf and line, ret 1
       }
*line = ft_strjoin(*line, buf);
 if (!*line)
    return (clean(list, buf, line, 5)); // clean buf, ret - 1
}
return (0);
}

int check_in_memory(char **line, char *buf, s_list *list)
{
    char    *is_n;
    char *tmp;
    int len;
    
    is_n = ft_strchr(list->memory);
    len = ft_strlen(list->memory);

    if (is_n == NULL)
        {
            *line = ft_strdup(list->memory);
            if (!*line)
                return (-1);
            return (clean(list, buf, line, 2)); // rturn 0 + clean memory
        }
    is_n[0] = '\0';
    *line = ft_strdup(list->memory);
    if (is_n - list->memory + 1 != len)
       {
           tmp = ft_strdup(is_n + 1);
            if (!*line || !tmp)
                return (-1);
            free(list->memory);
            list->memory = tmp;
            return (1);
       }
    return ((clean(list, buf, line, 2)) + 1); // return 1 + clean memory
}