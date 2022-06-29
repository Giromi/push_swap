#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(int ac, char *av[])
{
	printf("%s => %d\n", av[1], ft_atoi(av[1]));
	printf("%s => %d\n", av[1], atoi(av[1]));
	return (0);
}
