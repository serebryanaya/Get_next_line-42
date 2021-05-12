#include "get_next_line.h"
#include <stdio.h> // FIXME!!!

char *reading(int fd, char **ptr)
{
    char    *buffer;
    char    *join;
    int     bytes;

    
    if (BUFFER_SIZE <= 0 || !(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (NULL);
    if (*ptr == NULL)
        *ptr = ft_strdup("\0");
    while (!(ft_strchr(*ptr, '\n'))) // не встретили '\n'
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 0)
            return (NULL);
        buffer[bytes] = '\0';
        join = ft_strjoin(*ptr, buffer);
        free(*ptr);
        *ptr = join;
        if (!bytes)
            break;
    }
    free(buffer);
    return (*ptr);
}

int get_next_line(int fd, char **line)
{
    static char *ptr[1000];
    char    *is_n;
    char    *leak;
    
    ptr[fd] = reading(fd, &ptr[fd]);
    printf("ptr[fd] = %s\n", ptr[fd]);// FIXME 
    if (fd < 0 || !line || !ptr[fd]) // FIXME - add string up
   // if (fd < 0 || !line || !(ptr[fd] = reading(fd, &ptr[fd]))) // последнее значит, что мы что-то проитали до '\n'
        return (-1);
    is_n = ft_strchr(ptr[fd], '\n');
    printf("is_n = %s\n", is_n);// FIXME 
    if (is_n != NULL) 
        {
            leak = ptr[fd];
            *line = ft_substr(ptr[fd], 0, is_n - ptr[fd]); // в лайн кладем то, что вырезали ДО '\n'
            ptr[fd] = ft_strdup(is_n + 1);
            free(leak);
            return (1);
        }
    else //если нет '\n'
    {
        *line = ft_strdup(ptr[fd]); // записываем в лайн то, что прочли в reading
        free(ptr[fd]);
        ptr[fd] = NULL;
        return (0);
    }
}




/*
char    *find_field(char **ptr, char *treasure)
{
    char *s;

    *ptr = ft_strchr(treasure, '\n');
    if (*ptr)
    {
        s = ft_substr(treasure, 0, ptr - treasure);
        
    }

}


s_list *new_list(int fd)
{
    s_list *new_list;

    new_list = malloc(sizeof(s_list));
    if (!new_list)
        return (NULL);
    new_list->fd = fd;
    new_list->treasure = NULL;
    new_list->next = NULL;
    return (new_list);
}

int find_n(int fd, char **line, char *treasure)
{
    char    *buffer;
    char    *ptr;
    char    *tmp;
    int     bytes;

    ptr = NULL;
    bytes = 1;
    *line = MOK(&ptr, treasure); //FIXME
    bytes = read(fd, buffer, BUFFER_SIZE);
    while (ptr == NULL && bytes != 0)
    {
        buffer[bytes] = '\0';
        if ((ptr = ft_strchr(buffer, '\n')) != NULL)
        {
            *ptr = '\0';
            ptr++;
            *treasure = ft_strdup(ptr);
        }
        tmp = *line;
        if (!(*line = ft_strjoin(*line, buffer)) || bytes < 0)
            return (-1);
        printf("line in loop = %s\n", *line);
        free(tmp);
        tmp = NULL;
    }
    if (bytes || ft_strlen(*line) || ft_strlen(treasure)) //- значит, еще не все считали
        return (1);
    return (0);
}


int get_next_line(int fd, char **line)
{
    static s_list *list; // default null
    s_list *tmp;
    int ret_value;

    ret_value = -1;
    if (fd < 0 || !line) // || BUFFER_SIZE <= 0)!!!
        return (ret_value);
    if (!list)
        list = new_list(fd);
    tmp = list; // сохраняем указатель на лист
    while (tmp->fd != fd)
    {
        if (tmp->next == NULL)
            tmp->next = new_list(fd);
        tmp = tmp->next;
    }
    ret_value = find_n(fd, line, tmp->treasure);
    return (ret_value);
}

*/


/*
    
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    buff_to_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    //saved = buff_to_read;
    if (buff_to_read == 0)
        return (-1);
    ptr = find_field(saved, line)
    bytes = 1;
    while (!ptr || bytes != 0) // FIXME! и что-то есть в остатке
    {
        bytes = read(fd, buff_to_read, BUFFER_SIZE);
        if ((ptr = ft_strchr(buff_to_read, '\n')))
        {
            *ptr = '\0';
            ptr++;
            saved = ft_strdup(ptr); // в остатке сейчас вся оставшаяся линия, с \n до \0
         }



        printf("bytes: %d\n", bytes); // FIXME!
        if (bytes < 0)
        {
            free(buff_to_read);
            return (-1);      
        }
        buff_to_read[bytes] = '\0';
        saved = ft_strjoin(saved, buff_to_read);
        printf("saved: %s\n", saved); // FIXME!
    }
    free(buff_to_read);
    *line = find_line;
    saved = find_saved;
    if (bytes == 0)
        return(0);
    return (1);
}*/