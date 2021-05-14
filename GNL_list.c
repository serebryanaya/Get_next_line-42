#include "get_next_line.h"

s_list  *create_list(int fd)
{
    s_list  *new_list;

    new_list = malloc(sizeof(s_list));
    if (new_list == NULL)
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
    printf("string 22: is_n = %s\n", is_n); //FIXME
    if (is_n != NULL) //то есть нашли \n
    {
        new_mem = ft_substr(memory, 0, is_n - memory);
        tmp = ft_memccpy(memory, is_n + 1, '\n');
        ft_myzero(tmp);
    }
    else //если не нашли \n
    {
        new_mem = ft_calloc(ft_strlen(memory) + 1, sizeof(char));
        ft_strlcat(new_mem, memory, BUFFER_SIZE + 1);
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
        {
            *line = search_in_mem(is_n, memory); //кладем в лайн остаток. и переделываем is_n
            printf("string 49: line after search in mem = %s\n", *line); //FIXME
        }
    else
        return (-1); // FIXME!!!!
    bytes = read(fd, buffer, BUFFER_SIZE);
    while (is_n == NULL && bytes > 0)
    { // сюда идем, если не было остатка!
        printf("string 56: bytes = %d\n", bytes); //FIXME
        buffer[bytes] = '\0';
        printf("string 58: buff = %s\n", buffer); //FIXME
        //is_n = ft_strchr(buffer, '\n');
        //printf("string 60: is_n = %s\n", is_n); //FIXME
        if ((is_n = ft_strchr(buffer, '\n')) != NULL)
            {
                ft_strlcat(memory, ++is_n, BUFFER_SIZE + 1);
                printf("string 64: memory = %s\n", memory); //FIXME
                printf("string 645: is_n = %s\n", is_n); //FIXME
                ft_myzero(--is_n);
                printf("string 67: memory = %s\n", memory); //FIXME
                printf("string 68: is_n = %s\n", is_n); //FIXME
            }
        copy_line = *line;
        printf("string 71: copy_line = %s\n", copy_line);//FIXME
        *line = ft_strjoin(copy_line, buffer); // тут просто буфер, потому что освободила \n т.е. после него нет ничего в буфере
        printf("string 73: line + buf = %s\n", *line);//FIXME
        if (!line)
            return (-1);
        free(copy_line);
        copy_line = NULL;
        printf("string 78: copy_line = %s\n", copy_line);//FIXME
        bytes = read(fd, buffer, BUFFER_SIZE);
    }
    if (ft_strlen(*line) != 0)
     {
         printf("string 82: ft_strlen(*line) = %zu\n", ft_strlen(*line));//FIXME
        return (1);
     }
    printf("string 85: ft_strlen(*line) = %zu\n", ft_strlen(*line));//FIXME
    return (0);
}

int get_next_line(int fd, char **line)
{
    static s_list  *list;
    s_list  *copy_list;
    int return_value = 0;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    printf("string 97: fd current = %d\n", fd); //FIXME
    if (list == NULL)
        {
            list = create_list(fd);
            if (list == NULL)
                return (-1);
        }
    printf("string 104: list = %s\n", list->memory); //FIXME
    copy_list = list;
    while (copy_list->fd != fd)
    {
        if (copy_list->next == NULL)
            copy_list->next = create_list(fd);
        copy_list = copy_list->next;
    }
    printf("string 112: copy_list = %s\n", copy_list->memory); //FIXME
    printf("string 113: copy_list fd = %d\n", copy_list->fd); //FIXME
    //reading(fd, copy_list->memory, line);
    return_value = reading(fd, copy_list->memory, line);
    printf("string 116: ret_val = %d\n", return_value); //FIXME
    return (return_value);
}