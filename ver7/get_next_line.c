#include "get_next_line.h"
#include <stdio.h> // FIXME!

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_mystrchr(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		if (buf[i] != '\n')
			{
                i++;
                                                          //printf("str24 strchr: : str[i] = %c\n", str[i]);//FIXME!                  
            }
		else
			{
                buf[i] = '\0';
                                                            printf("str29 strchr: : buf[i - 1] = %c\n", buf[i - 1]);//FIXME!  
                return (&buf[i]);
                }

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
                                                            printf("str77 join: : join = %s\n", join);//FIXME! 
	return (join);
}

int find_n(char *buf, char **line, char *memory)
{
    char *is_n;
    char *tmp;

                                                        printf("str80 find_n: : buf = %s\n", buf);//FIXME! 
                                                         printf("str81 find_n: : line = %s\n", *line);//FIXME!                                                              
                                                        printf("str82 find_n: : memory = %s\n", memory);//FIXME!   
    is_n = ft_mystrchr(buf);
                                                        printf("str84 find_n: : in_s = %s\n", is_n);//FIXME!    
    tmp = *line;
    *line = ft_strjoin(*line, buf);
                                                        printf("str104 find_n: : line = %s\n", *line);//FIXME!                                                        

    if (!*line)
        return (0);
    /*if (is_n != NULL)
    {
                                                        printf("str92 find_n: line = %s\n", *line);//FIXME!  
        tmp = *line;
        //is_n[0] = '\0\;
        *line = ft_strjoin(*line, buf);
                                                         printf("str96 find_n: : line = %s\n", *line);//FIXME! 
        free(tmp);
        tmp = NULL;
                                                         printf("str102 find_n: : memory = %s\n", memory);//FIXME!  
        */
       if (is_n != NULL && (is_n - buf > 0))
            {
                //tmp = memory;
                //free(memory);//????
                memory = ft_strdup(is_n + 1);
                                                         printf("str103 find_n: : memory = %s\n", memory);//FIXME! 
                //free(tmp);
                //tmp = NULL;
                return (1);
            }
                                                         printf("str110 find_n: : buf = %s\n", buf);//FIXME!    
                                                         printf("str104 find_n: : line = %s\n", *line);//FIXME!                                                        
                                                         printf("str106 find_n: : memory = %s\n", memory);//FIXME!   
    return (0);
}

int clean(char *memory, char *buf, char **line, int tag)
{
    if (tag == 1)
    {
        free(memory);
        memory = NULL;
        free(*line);
        *line = NULL;
        return (-1);
    }
    if (tag == 2)
    {
    free(memory);
    memory = NULL;
    return (0);
    }
    if (tag == 3)
    {
        free(*line);
        *line = NULL;
        return (-1);
    }
        if (tag == 4)
    {
        free(buf);
        buf = NULL;
        free(*line);
        *line = NULL;
        return (-1);
    }
    if (tag == 5)
    {
        free(buf);
        buf = NULL;
        return (-1);
    }

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

int list_check(int fd, s_list **list, char **line)
{
    s_list  *copy_list;
            
        if (*list == NULL)
        {
        *list = create_list(fd);
        if (*list == NULL)
            return (-1);
        }
    copy_list = *list;
    while (copy_list->fd != fd)
    {
        if (copy_list->next == NULL)
            copy_list->next = create_list(fd);
        copy_list = copy_list->next;
    }
    *line = ft_strdup("\0");
    free(*line);
    if (!*line)
        return (-1);
    *line = malloc(sizeof(char) * (ft_strlen(copy_list->memory) + 1));
    if (!*line)
        return (-1);
    *line = ft_strdup(copy_list->memory);
    return(0);
}

int get_next_line(int fd, char **line)
{
    int bytes;
    static  s_list  *list;
    char    *tmp[1];
    char buf[BUFFER_SIZE + 1];

                                                        printf("str154 GNL\n");//FIXME!
                                                        printf("str156 : fd = %d\n", fd);//FIXME!
                                                        list_check(fd, &list);
                                                        printf("str158 : list->fd = %d\n", list->fd);//FIXME!
                                                        printf("str158 : readtest = %zd\n", read(fd, tmp, 0));//FIXME!
     if (fd < 0 || !line || list_check(fd, &list) < 0 || (read(fd, tmp, 0) < 0) \
        || BUFFER_SIZE < 1)
        {
                                                         printf("str163 GNL reading error\n");//FIXME!           
        return (-1);
        }
    *line = ft_strdup("\0");
                                                        printf("str181 : line = %s\n", *line);//FIXME!
    if (!*line)
        return (-1);
                                                        printf("str192 : memory = %s\n", list->memory);//FIXME! 
    bytes = 1;
    while (bytes > 0)
    {
                                                        printf("str195 : buf = %s\n", buf);//FIXME!      
    bytes = read(fd, buf, BUFFER_SIZE);
                                                        printf("str195 : bytes = %d\n", bytes);//FIXME!  
    buf[bytes] = '\0';
                                                        printf("str221 : buf = %s\n", buf);//FIXME!  
    if (find_n(buf, line, list->memory) == 1)
            {
                                                         printf("str197 : memory = %s\n", list->memory);//FIXME!             
                return (1);
            }
    }
    return (clean(list->memory, line, 0));
}