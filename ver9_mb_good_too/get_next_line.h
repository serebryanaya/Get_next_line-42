#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct get_next_line
{
    int fd;
    char *memory;
    struct get_next_line *next;
}       s_list;

char	*ft_strchr(char *str, char c);
char	*ft_strjoin (char *s1, char *s2);
char	*ft_substr(char *s, int start, size_t len);
void	ft_myzero(char *str);
size_t	ft_strlen(char *s);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);

int get_next_line(int fd, char **line); //FIXME! проверить, что все эти функции используются!
int reading(int fd, char *memory, char **line); ////FIXME! 
char *search_in_mem (char *is_n, char *memory); ////FIXME!
s_list  *create_list(int fd); ////FIXME! 


#endif