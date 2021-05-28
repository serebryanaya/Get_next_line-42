#include "get_next_line.h"
#include <stdio.h> // FIXME!

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *buf)
{
	size_t	i;

	i = 0;
	while (*(buf + i) != '\n' && *(buf + i) != '\0')
		{
                i++;
                                                          //printf("str24 strchr: : str[i] = %c\n", *(buf+i));//FIXME!                  
            }
   if (*(buf + i) != '\0')
        {
            (buf + i)[0] = '\0';
            return (buf + i);
                                                           //printf("str29 strchr: : buf bef ret = %c\n", *(buf+i));//FIXME!  
        }
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
    size_t i;

	i = 0;
    dup = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	while (s1[i] != '\0')
        {
            dup[i] = s1[i];
            i++;
        }
        dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin (char *line, char *buf)
{
	size_t	i;
	size_t	j;
	char			*join;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buf) + 1));
	if (!join)
		return (NULL);
	while (line[i] != '\0')
	{
		join[i] = line[i];
		i++;
	}
	while (buf[j] != '\0')
	{
		join[i] = buf[j];
		i++;
		j++;
	}
	join[i] = '\0';
    if (ft_strlen(join) != (ft_strlen(line) + (ft_strlen(buf))))
        {
            free(join);
            return (NULL);
        }
                                                            //printf("str77 join: : join = %s\n", join);//FIXME! 
	return (join);
}

int clean(s_list list, char **buf_or_line)
{
    if (*buf_or_line)
    {
        free(*buf_or_line);
        *buf_or_line = NULL;
    }
    if (*list->memory)
       {
        free(*list->memory);
        *list->memory = NULL;
    }
    return (-1);
}

s_list  *create_list(int fd)
{
    s_list  *new_list;
 
    new_list = malloc(sizeof(s_list));
                                                             //printf("str125 : new_list->fd = %d\n", new_list->fd);//FIXME!
    if (new_list == NULL)
        return (NULL);
    new_list->fd = fd;
                                                                 //printf("str128 : new_list->fd = %d\n", new_list->fd);//FIXME!

    new_list->memory = ft_strdup("\0");
                                                                 //printf("str131 : memory->fd = %s\n", new_list->memory);//FIXME!

    if (new_list->memory == NULL)
        {
            free(new_list);
            new_list = NULL;
            return (NULL);
        }
    new_list->len = 0;;
    new_list->next = NULL;
    return (new_list);
}

s_list *list_check(int fd, s_list *list)
{
    s_list  *copy_list;
                                                                //printf("list_check\n");//FIXME
    if (!list)
    {
        list = create_list(fd); // may NULL will return. so need to do return -1
        if (list == NULL)
            return (-1);
    }
    
    copy_list = list;     
   /* if (list == NULL)
        {
        copy_list = create_list(fd);
                                                                //printf("str153 : copy_list->fd = %d\n", copy_list->fd);//FIXME!
            if (copy_list == NULL)
                {
                                                                 //printf("str154 : copy_list->fd = %d\n", copy_list->fd);//FIXME!
                return (NULL);
                }
                                                                //printf("str156 : copy_list->fd = %d\n", copy_list->fd);//FIXME!
            return (copy_list);
        }*/
    while (copy_list->fd != fd)
    {
        if (copy_list->next == NULL)
            {
            copy_list->next = create_list(fd);
            if (copy_list->next == NULL)
                return (NULL);
            }
        copy_list = copy_list->next;
    }
                                                            //printf("str164 : copy_list->memory = %s\n", copy_list->memory);//FIXME!
                                                           //printf("str165 : copy_list->fd = %d\n", copy_list->fd);//FIXME!
    return (copy_list);
}

int check_in_memory(char **line, s_list *list)
{
    int i;
    int j;

    if (!(*list->memory))
        return (0);
    i = list->index;
    while ((list->memory + i) != '\0' && (list->memory + i) != '\n')
        i++;
    line = malloc(sifeof(char) * (((list->memory + i) - list->index) + 1));
    if (!line)
        return (-1);
    j = 0;
    while (list->index < i)
        (*line)[j++] == list->memory[list->index++];
    (*line)[j] = '\0';
    if (list->memory[list->index] == '\n')
        {
        list->index++;
        return (1);
        }
    list->index = 0;
    free(list->memory);
    list->memory = NULL;
    return (0);
}

int my_split(char *buf, char **line_or_mem)
{
char *tmp;
size_t i;
size_t j;

i = ft_strlen(*line_or_mem);
j = ft_strlen(buf);
tmp = malloc(sizeof(char) * (i + j + 1));
if (!tmp)
    return (-1);
tmp = ft_strjoin(*line_or_mem, buf);
free(*line_or_mem);
*line_or_mem = tmp;
    return (0);
}

int ft_read(char **line, s_list *list)
{
size_t bytes;
size_t i;

buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));

                                                        //printf("str213 FT_READ\n");//FIXME!
                                                        //printf("str214 : buf before = %s\n", buf);//FIXME!
    if (!buf)
        return (-1);

bytes = 1;
while (bytes > 0)
{
bytes = read(fd, buf, BUFFER_SIZE);
i = 0;
while (buf[i] != '\n' && i < bytes)
    i++;
buf[i] = '\0';
if (bytes < 0 || my_split(buf, line) != 0)
    return(clean(list, &buf));
if (i < bytes)
{
buf[bytes] = '\0';
if (my_split((buf + i + 1), &list->memory) != 0)
    return(clean(list, &buf));
}
}
free(buf);
return (0);
}

int get_next_line(int fd, char **line)
{
    static  s_list  *list;
    int ostatok;
    int read_it;
    s_list *current_list;
                                                        //printf("str239 : fd = %d\n", fd);//FIXME!
                                                            //printf("str242 : line = %s\n", *line);//FIXME!
    if (fd < 0 || !line || (read(fd, 0, 0) != 0) || BUFFER_SIZE < 1)       
       return (-1);
    
    current_list = list_check(fd, list);
    if (!current_list)
    return (-1);
                                                        //printf("str158 : current_list->fd = %d\n", current_list->fd);//FIXME!
                                                        //printf("str158 : current_list->len = %zu\n", current_list->len);//FIXME!                                                        
                                                        //printf("str242 : line = %s\n", *line);//FIXME!
   //line = ft_strdup("\0"); // leaks!
                                                        //printf("str250 : line = %s\n", *line);//FIXME!
                                                        //printf("str252 : current_list->memory = %s\n", current_list->memory);//FIXME!                                                       
    
*line = NULL;
ostatok = check_in_memory(line, current_list);
                                                        //printf("str255 : ostatok = %d\n", ostatok);//FIXME! 
                                                        //printf("str256 : line = %s\n", *line);//FIXME!
                                                        //printf("str257 : current_list->memory = %s\n", current_list->memory);//FIXME!                                                      
if (ostatok == 1)
    return (ostatok);
                                                        /*printf("str267 : line = %s\n", *line);//FIXME!
                                                        //printf("str268 : current_list->memory = %s\n", current_list->memory);//FIXME! 
                                                        //printf("str269 : buf = %s\n", buf);//FIXME! */
if (ostatok == -1)
    return (clean(list, line));
    
read_it = ft_read(line, current_list);
                                                        //printf("str271 : fd = %d\n", fd);//FIXME! 
                                                        //printf("str272 : line = %s\n", *line);//FIXME!
                              
                              
                                                       //printf("str273 : current_list->memory = %s\n", current_list->memory);//FIXME! 
                                                        //printf("str274 : buf = %s\n", buf);//FIXME! 
if (read_it)
    return (clean(list, line));
if (!current_list->memory)
    return (0);
return (1);
}