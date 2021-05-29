#include "get_next_line_bonus.h"

int	clean(t_list **list, char **buf_or_line)
{
	if (*buf_or_line)
	{
		free(*buf_or_line);
		*buf_or_line = NULL;
	}
	if (*list != NULL)
	{
		free(*list);
		*list = NULL;
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*list;
	int				ostatok;
	int				read_it;
	t_list			*c_list;

	if (fd < 0 || !line || (read(fd, 0, 0) != 0) || BUFFER_SIZE < 1)
		return (-1);
	if (!list)
		list = create_list(fd);
	c_list = list_check(fd, list);
	if (!list || !c_list)
		return (-1);
	*line = NULL;
	ostatok = check_in_memory(line, &(c_list->memory), &(c_list->index));
	if (ostatok == 1)
		return (ostatok);
	if (ostatok == -1)
		return (clean(&c_list, line));
	read_it = ft_read(line, c_list);
	if (read_it != 0)
		return (clean(&c_list, line));
	if (!c_list->memory)
		return (0);
	return (1);
}
