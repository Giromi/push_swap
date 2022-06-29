
#include <unistd.h>
#include <stdlib.h>


int	main(void)
{
	char	*buf;
	int		len;

	len = 2;
	buf = (char *)malloc(sizeof(char) * (len + 1));
	read(0, buf, len);
	write(1, buf, 2);
	return 0;
}
