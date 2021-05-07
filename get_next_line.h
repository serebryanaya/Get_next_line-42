#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int get_next_line(int fd, char **line);

typedef struct get_next_line
{
    int fd;
    char *reminder;
    struct get_next_line *next;
}       gnl_struct;

#endif