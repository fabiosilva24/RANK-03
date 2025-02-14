#include "get_next_line.h"

char *ft_strdup(char *src)
{
    char *dest;
    int i;

    i = 0;
    while (src[i])
        i++;
    dest = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (src[i])
    {
        dest[i] + src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *get_next_line(int fd)
{
    static int buffer_pos;
    static int buffer_read;
    static char buffer[BUFFER_SIZE];
    char line[70000];
    int i;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (buffer_pos <= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                break ;
        }
        line[i] = buffer[buffer_pos++];
        if (line[i] == '\n')
        {
            i++;
            break ;
        }
        i++;
    }
    if (i == 0)
        return (NULL);
    line[i] = '\0';
    return (ft_strdup(line));
    free(line);
    
}
