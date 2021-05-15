#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // FIXME!!!
#include <fcntl.h> // for OPEN
//#include "./libft/libft.h"
#include "get_next_line.h"

//#define BUFFER_SIZE 32  //DELETE!>
/*
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



int get_next_line(int fd, char **line)
{
    char buff[BUFFER_SIZE + 1];
    int byte_was_read;
    char    *p_n;
    static char *reminder;
    char *tmp;

    p_n = check_reminder(reminder, line);
    while (!p_n && (byte_was_read = read(fd, buff, 10)))
    {
        buff[byte_was_read] = '\0';
        if ((p_n = ft_strchr(buff, '\n')))
        {
            *p_n = '\0';
            p_n++;
            reminder = ft_strdup(p_n);
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

int main (void)
{
    char *line;
    int fd;

    line = "hello, world!";
//    printf("line first = %s\n", line);
    fd = open("test_text.txt", O_RDONLY); // file name, flag
 //   printf("fd = %d\n", fd);
    get_next_line(fd, &line);
    printf("line 1st = %s\n", line);

    get_next_line(fd, &line);
    printf("line 2nd = %s\n", line);

    get_next_line(fd, &line);
    printf("line 3th = %s\n", line);

    while (get_next_line(fd, &line)) // пока есть что читать
        printf("line finish = %s\n", line); // смотрим вывод строки
        printf("return GNL = %d\n", get_next_line(fd, &line)); // смотрим возврат функции
}

int main (void)
{
    char *line;
    int fd;

    line = "hello, world!"; // len = 13
    printf("line default = %s\n", line);
    fd = open("test_text.txt", O_RDONLY); // file name, flag
 //   printf("fd = %d\n", fd);
    get_next_line(fd, &line);
    printf("запись в line на 10 байт = %s\n", line);

    get_next_line(fd, &line);
    printf("line 2nd = %s\n", line);

    get_next_line(fd, &line);
    printf("line 3th = %s\n", line);

    while (get_next_line(fd, &line)) // пока есть что читать
        printf("line finish = %s\n", line); // смотрим вывод строки
        printf("return GNL = %d\n", get_next_line(fd, &line)); // смотрим возврат функции
//while (1);
}*/

int main (void)
{
    char *line;
    int fd;
    int fd2;
    int counter;

    counter = 0;
    line = "hello, world!";
    
    printf("str 143: line first = %s\n", line);
    fd = open("test_text.txt", O_RDONLY); // file name, flag
    printf("fd = %d\n", fd); //FIXME

   
    fd2 = open("test_text_long.txt", O_RDONLY); 
    //printf("fd2 = %d\n", fd2); //FIXME


    while (counter < 2 && get_next_line(fd, &line))
        {
        printf("CIRCLE 1!!!! line finish = %s\n", line);
        counter++; 
        printf("counter = %d\n", counter); //FIXME  
        }
    printf("fd2 = %d\n", fd2); //FIXME*/
    while (counter < 10 && get_next_line(fd2, &line))
        {
        printf("fd2 = %d\n", fd2); //FIXME
        printf("CIRCLE 2!!!! line finish = %s\n", line);
        counter++;
        }
        while (get_next_line(fd, &line) && counter < 15)
        {
        printf("CIRCLE 3!!!! line finish = %s\n", line);
        counter++;   
        }
        //while (1);
        return (0);
}