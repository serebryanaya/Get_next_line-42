#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

s_list  *create_list(int fd)
{
    s_list  *new_list;
 
    new_list = malloc(sizeof(s_list));
    if (new_list == NULL)
        return (0);
    new_list->fd = fd;
    new_list->memory = malloc((BUFFER_SIZE + 1) * sizeof(char));
	(new_list->memory)[0] = '\0';
    new_list->next = NULL;
    return (new_list);
}

char *search_in_mem (char *is_n, char *memory)
{
    char *new_mem;
    char *tmp;

    is_n = ft_strchr(memory, '\n');
    if (is_n != NULL)
    {
        new_mem = ft_substr(memory, 0, is_n - memory);
        tmp = ft_substr(memory, is_n - memory + 1, ft_strlen(is_n));
        ft_myzero(memory);
        ft_strlcat(memory, tmp);
        free(tmp);
        tmp = NULL;
    }
    else
    {
        new_mem = malloc((ft_strlen(memory) + 1) * sizeof(char));
        new_mem[0] = '\0';
        ft_strlcat(new_mem, memory);
        ft_myzero(memory);
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
    bytes = 1;
    if (ft_strchr(memory, '\n'))
        {
            *line = search_in_mem(is_n, memory);
            return (1);
        }
    *line = search_in_mem(is_n, memory);
    while (is_n == NULL && (bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes] = '\0';
        if ((is_n = ft_strchr(buffer, '\n')) != NULL)
            {
                ft_strlcat(memory, ++is_n);
                ft_myzero(--is_n);
            }
        copy_line = *line;
        *line = ft_strjoin(copy_line, buffer);
        if (!line || bytes < 0)
            return (-1);
        free(copy_line);
        copy_line = NULL;
    }
    if (ft_strlen(*line) != 0 || ft_strlen(memory) != 0 || bytes > 0)
        return (1);
    return (0);
}

int get_next_line(int fd, char **line)
{
    static s_list  *list;
    s_list  *copy_list;

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
    return (reading(fd, copy_list->memory, line));
}