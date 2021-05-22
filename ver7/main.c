#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 
#include <fcntl.h>
#include "get_next_line.h"

int main (int argc, char **argv)
{
int fd;
//int fd2 = 0;
char *line = NULL;
int value = 0;
int counter = 0;

if (argc < 1)
{
                                                printf("No arguments\n");
    return (-1);
}
if (argc == 1)
    {
        fd = 0;
                                                printf("str24 main\n");
    }
else
{
    fd = open(argv[1], O_RDONLY);
    if (!fd)
        {
                                                printf("str29 main: error in open\n");
    //fd2 = open(argv[2], O_RDONLY);
        return (0);
        }
    else
                                                        printf("str28 main\n");
}
    while (counter < 1)
        {
                                                        printf("str41 main\n");
            value = get_next_line(fd, &line);
                                                         printf("ret_val = %d, line = %sZZZ\n", value, line);
            counter++;
        }
                                                        printf("str46 main\n");
    if (line != NULL)
        free(line);
    /*while (counter < 6)
        {
            value = get_next_line(fd2, &line);
            printf("ret_val = %d, line = %s", value, line);
            counter++;
        }
    printf("str45 main");
    free(line);
    while (counter < 9)
        {
            value = get_next_line(fd, &line);
            printf("ret_val = %d, line = %s", value, line);
            counter++;
        }
    printf("str53 main");
    free(line);*/
    close(fd);
    //close(fd2);
return (0);
}