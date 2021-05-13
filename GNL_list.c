#include "get_next_line.h"

s_list  *create_list(int fd);
{
    s_list  *new_list;

    new_list = malloc(sizeof(s_list));
    if (new_list == NULL);
        return (0);
    new_list->fd = fd;
    new_list->memory = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    new_list->next = NULL;
    return (new_list);
}

char *search_in_mem (char *is_n, char *memory) //переделывает is_n и ищет \n в остатке
{
    char *new_mem;
    char *tmp;

    is_n = ft_strchr(memory, '\n');
    if (is_n != NULL) //то есть нашли \n
    {
        new_mem = ft_substr(memory, 0, is_n - memory);
        tmp = ft_memccpy(memory, is_n + 1, 10);
        ft_bzero(tmp, is_n - memory);
    }
    else //если не нашли \n
    {
        new_mem = malloc(sizeof(char) * (ft_strlen(memory) + 1));
        strlcat(new_mem, memory, BUFFER_SIZE + 1);
        free(memory);
        memory = NULL;
    }
    return (new_mem);
}

int reading(int fd, char *memory, char **line)
{
    char buffer[BUFFER_SIZE + 1];
    char *copy_line;
    char *is_n;
    int bytes;

    is_n = NULL;
    if (memory != NULL)
        *line = search_in_mem(is_n, memory) //кладем в лайн остаток. и переделываем is_n
    while (is_n == NULL && (bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    { // сюда идем, если не было остатка!
        buffer[bytes] = '\0';
        is_n = ft_strchr(buffer, '\n');
        if (is_n != NULL)
            {
                strlcat(memory, is_n, BUFFER_SIZE + 1);
                free(is_n);
                is_n = NULL;
            }
        copy_line = line;
        *line = ft_strjoin(copy_line, buffer); // тут просто буфер, потому\
         что я освободила \n т.е. после него нет ничего в буфере
        if (!line)
            return (-1);
        free(copy_line);
        copy_line = NULL;
    }
    if (ft_strlen(*line) != 0)
        return (1);
    return (0);
}

int get_next_line(int fd, char **line)
{
    static s_list  *list;
    s_list  *copy_list;
    int return_value;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    if (list == NULL)
        {
            list = create_list(fd);
            if (list == NULL)
                return (-1);
        }
    copy_list = list;
    while (copy_list->fd != fd)
    {
        if (copy_list->next == NULL)
            copy_list->next = create_list(fd);
        copy_list = copy_list->next;
    }
    return_value = reading(fd, copy_list->memory, line);
    return (return_value);
}