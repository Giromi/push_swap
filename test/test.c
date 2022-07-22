#include <unistd.h>
#include <stdlib.h>
#define BUFFERSIZE 4

int main ()
{
	char	*buf;
	int		rd;

	while (1)
	{
		buf = malloc(BUFFERSIZE);
		rd = read(0, buf, BUFFERSIZE);
		write(1, buf, BUFFERSIZE);
		if (rd == -1)
			break ;
		if (rd <= BUFFERSIZE)
			while (*buf != '\n' || *buf != '\0')
				buf++;
		free(buf);
		if (*buf == '\0')
			break ;
	}
	return (0);
}
