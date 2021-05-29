#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_get_next_line
{
	int						fd;
	size_t					index;
	char					*memory;
	struct s_get_next_line	*next;
}			t_list;

t_list	*create_list(int fd);
t_list	*list_check(int fd, t_list *list);
int		check_in_memory(char **line, char **memory, size_t *index);
int		clean(t_list **list, char **buf_or_line);
int		my_split(char *buf, char **line_or_mem);
int		ft_read(char **line, t_list *list);
int		get_next_line(int fd, char **line);

#endif
