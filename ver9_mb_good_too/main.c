#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 
#include <fcntl.h>
#include "get_next_line.h"

int main (int argc, char **argv)
{
int fd;
int fd2;
char *line = NULL;
int value = 0;
int counter = 0;

if (argc < 1)
{
                                                printf("No arguments\n");
    return (-1);
}
/*if (argc == 1)
    {
        fd = 0;
                                                printf("str24 main\n");
    }*/
else
{
    fd = open(argv[1], O_RDONLY);

                                                //printf("str29 main: error in open\n");
    fd2 = open(argv[2], O_RDONLY);

                                                        printf("str28 main\n");
}
    while (counter < 1)
        {
                                                        printf("str41 main\n");
            value = get_next_line(fd, &line);
                                                         printf("FILE 1: ret_val = %d, line = %s*THE END*\n", value, line);
            counter++;
        }
    while (counter < 3)
        {
            value = get_next_line(fd2, &line);
                                                    printf("FILE 2: ret_val = %d, line = %s*THE END*\n", value, line);
            counter++;
        }
                                                    printf("str51 main\n");
    while (counter < 5)
        {
            value = get_next_line(fd, &line);
                                                printf("FILE 1 again: ret_val = %d, line = %s*THE END*\n", value, line);
            counter++;
        }
                                                    printf("str58 main\n");
    if (line != NULL)
        free(line);
    close(fd);
    close(fd2);
return (0);
}