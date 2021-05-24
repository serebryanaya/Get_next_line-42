#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*typedef struct get_next_line
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
size_t	ft_strlcat(char *dst, char *src);


int get_next_line(int fd, char **line); //FIXME! проверить, что все эти функции используются!
int reading(int fd, char *memory, char **line); ////FIXME! 
char *search_in_mem (char *is_n, char *memory); ////FIXME!
s_list  *create_list(int fd); ////FIXME! 
char *search_ostatok (char *ostatok);
char *find_n (char *str);*/

/*typedef struct		s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}					t_arr;

t_arr				*ft_newlist(const int fd);
char				*checkrest(char **p_n, char *rest);
int					get_line(const int fd, char **line, char *rest);
int					get_next_line(const int fd, char **line);
*/

/*
int			get_next_line(int fd, char **line);
char		*join_and_free(char *s1, char *s2);
int			find_index(const char *s, int c);
int			get_line(char *str, char **line, int i);
char		*ft_substr(char const *s, int start, int len);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
*/

int					get_next_line(int fd, char **line);
int					has_return(char *str);

size_t				ft_strlen(const char *s);

char				*join_str(const char *s1, const char *s2);

#endif