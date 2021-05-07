#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h> // for OPEN
#include "../libft/libft.h"
#include "get_next_line.h"

#define BUFFER_SIZE 32 

void	ft_clear(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}

char *check_reminder(char *reminder, char **line)
{
char *p_n;

p_n = NULL;
if (reminder)
    {
        if ((p_n = ft_strchr(reminder, '\n')))
        {
            *p_n = '\0';
            *line = ft_strdup(reminder);
            p_n++;
            ft_strlcpy(reminder, p_n, (ft_strlen(p_n) + 1));
        }
        else // если не встретили \n в остатке
        {
            *line = ft_strdup(reminder);
            ft_clear(reminder); // затирает все знаки на '\0'
        }
    }
    else
    {
        *line = ft_calloc(1, sizeof(char));
    }
return (p_n);
}



int get_line(int fd, char **line, char **reminder)
{
    char buff[BUFFER_SIZE + 1];
    int byte_was_read;
    char    *p_n;
    char *tmp;

    p_n = check_reminder(*reminder, line);
    while (!p_n && (byte_was_read = read(fd, buff, 10)))
    {
        buff[byte_was_read] = '\0';
        if ((p_n = ft_strchr(buff, '\n')))
        {
            *p_n = '\0';
            p_n++;
            *reminder = ft_strdup(p_n);
        }
        tmp = *line;
        if (!(*line = ft_strjoin(*line, buff)) || byte_was_read < 0)
            return (-1);
        printf("line in loop = %s\n", *line);
        free(tmp);
    }
    if (byte_was_read != 0 || ft_strlen(*line) != 0) //- значит, еще не все считали
        return (1);
    return (0);
}

gnl_struct *new_list(int fd)
{
    gnl_struct *list;

    if (fd < 0 || line == NULL)
        return (-1);
    list = malloc(sizeof(gnl_struct));
    list->fd = fd;
    list->reminder = NULL;
    list->next = NULL;
    return (list);
}


int get_next_line(int fd, char **line)
{
    static gnl_struct *head; // default null
    gnl_struct *tmp;

    if (head == NULL)
        head = new_list(fd);
    tmp = head;
    while (tmp->fd != fd)
    {
        if(tmp->next == NULL)
            tmp->next = new_list(fd);
        tmp = tmp->next;
    }
    return (get_line(tmp->fd, line, &tmp->reminder));
}

int main (void)
{
    char *line;
    int fd1;
    int fd2;
    int counter;

    counter = 0;
    line = "hello, world!";
//    printf("line first = %s\n", line);
    fd1 = open("test_text.txt", O_RDONLY); // file name, flag
    fd2 = open("test_text_long.txt", O_RDONLY); 
    while (get_next_line(fd1, &line) && counter < 3)
        {
        printf("line finish = %s\n", line);
        counter++;   
        }
    while (get_next_line(fd2, &line) && counter < 6)
        {
        printf("line finish = %s\n", line);
        counter++;
        }
    while (get_next_line(fd1, &line) && counter < 9)
        {
        printf("line finish = %s\n", line);
        counter++;   
        }
        return (0);
}