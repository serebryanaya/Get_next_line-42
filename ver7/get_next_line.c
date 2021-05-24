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
   if (*(buf + i) == '\n')
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
                                                            //printf("str77 join: : join = %s\n", join);//FIXME! 
	return (join);
}

int clean(s_list *list, char *buf, char **line, int tag)
{
    if (tag == 1) // memory + line
    {
        free(list->memory);
        list->memory = NULL;
        free(*line);
        *line = NULL;
        return (-1);
    }
    if (tag == 2) // memory
    {
    free(list->memory);
    list->memory = NULL;
    return (0);
    }
    if (tag == 3) // line
    {
        free(*line);
        *line = NULL;
        return (-1);
    }
        if (tag == 4) // buf + line
    {
        free(buf);
        buf = NULL;
        free(*line);
                                                                     //printf("str103 : *line = %s\n", *line);//FIXME!
        *line = NULL;
        return (-1);
    }
    if (tag == 5) // buf
    {
        free(buf);
        buf = NULL;
        return (-1);
    }
     if (tag == 6) // buf + line + list
    {
        free(buf);
        buf = NULL;
        free(*line);
        *line = NULL;
        free(list->memory);
    list->memory = NULL;
        return (0);
    }
    return (0);
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
    new_list->next = NULL;
    return (new_list);
}

s_list *list_check(int fd, s_list *list)
{
    s_list  *copy_list;
                                                                //printf("list_check\n");//FIXME
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
            copy_list->next = create_list(fd);
        copy_list = copy_list->next;
    }
                                                            //printf("str164 : copy_list->memory = %s\n", copy_list->memory);//FIXME!
                                                           //printf("str165 : copy_list->fd = %d\n", copy_list->fd);//FIXME!
    return (copy_list);
}

int check_in_memory(char **line, char *buf, s_list *list)
{
    char    *is_n;
    char *tmp;
    int len;
    
    is_n = ft_strchr(list->memory);
                                                            //printf("str176 : memory = %s\n", list->memory);//FIXME!     
                                                            //printf("str177 : is_n = %s\n", is_n);//FIXME!                                                             
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

int ft_read(char **line, char *buf, s_list *list, int fd)
{
int bytes;
char *is_n;

bytes = 1;
while (bytes > 0)
{  
buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));

                                                        //printf("str213 FT_READ\n");//FIXME!
                                                        //printf("str214 : buf before = %s\n", buf);//FIXME!
    if (!buf)
        return (-1);
 bytes = read(fd, buf, BUFFER_SIZE);
                                                         printf("str218 : bytes = %d\n", bytes);//FIXME!
    if (bytes == 0)
        return (1 + clean(list, buf, line, 5)); // clean buf, line, list, ret 0
/*if (buf[bytes - 1] != '\0')
    {
        buf[bytes] = '\0';
                                                            //printf("str223 : buf = %s\n", buf);//FIXME!
    }
else
{
    *line = ft_strjoin(*line, buf);
                                                            //printf("str222 : *line = %s\n", *line);//FIXME!
    return (2 + clean(list, buf, line, 4)); // clean buf and line, ret 1
}*/
is_n = ft_strchr(buf);
                                                            //printf("str225 : is_n = %s\n", is_n);//FIXME!
if (is_n != NULL && (is_n - buf + 1 != ft_strlen(buf)))
       {
        list->memory = ft_strdup(is_n + 1);
                                                            //printf("str224 : memory = %s\n", list->memory);//FIXME!
            if (!list->memory)
                return (-1);
        is_n[0] = '\0'; 
        *line = ft_strjoin(*line, buf);
        return (2 + clean(list, buf, line, 5)); // clean buf and line, ret 1
       }
*line = ft_strjoin(*line, buf);
                                                        //printf("str234 : buf = %s\n", buf);//FIXME!
                                                        //printf("str231 : *line = %s\n", *line);//FIXME!
 if (!*line)
    return (clean(list, buf, line, 5)); // clean buf, ret - 1
if (bytes < BUFFER_SIZE)
    break ;
}
/*if (ft_strlen(*line))
    return (1);*/
return (0);
}

int get_next_line(int fd, char **line)
{
    static  s_list  *list;
    char    *tmp[1];
    char buf[BUFFER_SIZE + 1];
    int ostatok;
    int read_it;//del
    s_list *current_list;

    ostatok = 0;
 
                                                        //printf("str239 : fd = %d\n", fd);//FIXME!
    *line = ft_strdup("\0"); // leaks!
    if (fd < 0 || !line || (read(fd, tmp, 0) != 0) || BUFFER_SIZE < 1)       
       return (-1);
    if (!list)
        list = create_list(fd);
    current_list = list_check(fd, list);
    if (!current_list)
    return (-1);
                                                        //printf("str158 : current_list->fd = %d\n", current_list->fd);//FIXME!
                                                        //printf("str242 : line = %s\n", *line);//FIXME!
   //line = ft_strdup("\0"); // leaks!
                                                        //printf("str250 : line = %s\n", *line);//FIXME!
                                                        //printf("str252 : current_list->memory = %s\n", current_list->memory);//FIXME!                                                       
if (current_list->memory[0] != '\0')
    ostatok = check_in_memory(line, buf, current_list);
                                                        //printf("str255 : ostatok = %d\n", ostatok);//FIXME! 
                                                        //printf("str256 : line = %s\n", *line);//FIXME!
                                                        //printf("str257 : current_list->memory = %s\n", current_list->memory);//FIXME!                                                      
if (ostatok == 1)
    return (1);
else if (ostatok == -1)
    return (-1);
                                                        /*printf("str267 : line = %s\n", *line);//FIXME!
                                                        //printf("str268 : current_list->memory = %s\n", current_list->memory);//FIXME! 
                                                        //printf("str269 : buf = %s\n", buf);//FIXME! */
read_it = ft_read(line, buf, current_list, fd);
                                                        //printf("str271 : fd = %d\n", fd);//FIXME! 
                                                        //printf("str272 : line = %s\n", *line);//FIXME!
                                                        //printf("str273 : current_list->memory = %s\n", current_list->memory);//FIXME! 
                                                        //printf("str274 : buf = %s\n", buf);//FIXME! 

return (read_it);
}