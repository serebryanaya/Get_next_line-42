#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main (int argc, char **argv)
{
int fd = 0;
int fd2 = 0;
char *line = NULL;
int value = 0;

if (argc < 1)
{
    printf("No arguments");
    return (-1);
}
if (argc == 1)
    {
    while ((value = get_next_line(fd, &line)))
        printf("ret_val = %d, line = %s", value, *line);
    }
if (argc == 2)
    {
        fd = open("/Users/pveeta/Desktop/git_serebryanaya/2_get_next_line/test_text.txt", O_RDONLY);
    while ((value = get_next_line(fd, &line)))
        printf("ret_val = %d, line = %s", value, *line);
    }
if (argc == 3)
    {
    fd = open("/Users/pveeta/Desktop/git_serebryanaya/2_get_next_line/test_text.txt", O_RDONLY);
    while ((value = get_next_line(fd, &line)))
        printf("ret_val = %d, line = %s", value, *line);
        fd2 = open("/Users/pveeta/Desktop/git_serebryanaya/2_get_next_line/last.txt", O_RDONLY);
    while ((value = get_next_line(fd2, &line)))
        printf("ret_val = %d, line = %s", value, *line);
    while ((value = get_next_line(fd, &line)))
        printf("ret_val = %d, line = %s", value, *line);
    }
return (0);
}