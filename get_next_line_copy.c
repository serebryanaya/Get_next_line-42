#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *search_ostatok (char *ostatok)
{
    char *new_mem;
    char *tmp;
    char *now_n;

    if (ostatok == NULL)
        return (0);
    now_n = ft_strchr(ostatok, '\n');
    if (now_n != NULL)
    {
        new_mem = ft_substr(ostatok, 0, now_n - ostatok);
        printf("new_mem = %s\n", new_mem); //FIXME
         printf("ostatok = %s\n", ostatok); //FIXME
         printf("now_n - ostatok = %ld\n", (now_n - ostatok)); //FIXME
        tmp = ft_substr(ostatok, now_n - ostatok + 1, ft_strlen(now_n));
         printf("tmp = %s\n", tmp); //FIXME
         printf("ostatok = %s\n", ostatok); //FIXME
        ft_myzero(ostatok);
         printf("ostatok = %s\n", ostatok); //FIXME
        ft_strlcat(ostatok, tmp);
        printf("ostatok = %s\n", ostatok); //FIXME
        printf("tmp = %s\n", tmp); //FIXME
        free(tmp);
        tmp = NULL;
    }
    else
    {
        new_mem = malloc((ft_strlen(ostatok) + 1) * sizeof(char));
        new_mem[0] = '\0';
        ft_strlcat(new_mem, ostatok);
        ft_myzero(ostatok);
    }
    return (new_mem);
}

int get_next_line(int fd, char **line)
{
    static char *ostatok;
    char *is_n;
    char buffer[BUFFER_SIZE + 1];
    char *copy_line;
    int bytes;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    is_n = NULL;
    printf("line = %s\n", *line); //FIXME
    printf("ostatok = %s\n", ostatok); //FIXME
    if (ostatok == NULL)
        printf("ostatok = %s\n", ostatok); //FIXME
    *line = search_ostatok(ostatok);
                 printf("ostatok before = %s\n", ostatok); //FIXME
        if (line)
        {
             printf("ostatok = %s\n", ostatok); //FIXME
             return (1);           
        }

    while (is_n == NULL && (bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes] = '\0';
        printf("buffer = %s\n", buffer); //FIXME
        printf("is_n = %s\n", is_n); //FIXME
        if ((is_n = ft_strchr(buffer, '\n')) != NULL)
            {
                printf("is_n = %s\n", is_n); //FIXME
                ostatok = malloc(sizeof(char) * ft_strlen(is_n));
                        printf("ostatok = %s\n", ostatok); //FIXME
                ostatok[0] = '\0';
                ft_strlcat(ostatok, ++is_n);
                printf("ostatok = %s\n", ostatok); //FIXME
                printf("is_n) = %s\n", is_n); //FIXME
                ft_myzero(--is_n);
            }
        copy_line = *line;
        *line = ft_strjoin(copy_line, buffer);
        if (!line || bytes < 0)
            return (-1);
        free(copy_line);
        copy_line = NULL;
    }
    if (ft_strlen(*line) != 0 || ft_strlen(ostatok) != 0 || bytes > 0)
        return (1);
    return (0);
}