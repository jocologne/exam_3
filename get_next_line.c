#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	if(BUFFER_SIZE < 1 || fd < 0 || read(fd, NULL, 0) < 0)
		return(NULL);
	char *line = malloc(10000);
	char *buf =line;
	while (read(fd, buf, 1) > 0)
	{
		if (*buf == '\n')
		{
			buf++;
			break;
		}
		buf++;
	}
	if (buf > line)
	{
		*buf = '\0';
		return (line);
	}
	else
	{
		free(line);
		return(NULL);
	}
}