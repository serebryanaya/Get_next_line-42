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
int value = 1;
int counter = 1;

if (argc == 1)
        fd = 0;
else
{
    fd = open(argv[1], O_RDONLY);

                                                //printf("str29 main: error in open\n");
    fd2 = open(argv[2], O_RDONLY);

                                                       // printf("str28 main\n");
}
    
while (counter < 2)
    {
    value = get_next_line(fd, &line);
    printf("FINISH: fd = %d, ret_val = %d, line = %s*THE END*\n", fd, value, line);
    counter++;
    free(line);
    }
while (counter < 4)
    {
    value = get_next_line(fd2, &line);
    printf("FINISH: fd2 = %d, ret_val = %d, line = %s*THE END*\n", fd2, value, line);
    counter++;
    free(line);
    }
while (counter < 6)
    {
    value = get_next_line(fd, &line);
    printf("FINISH: fd = %d, ret_val = %d, line = %s*THE END*\n", fd, value, line);
    counter++;
    free(line);
    }
        //while (1) ;
return (0); 
}