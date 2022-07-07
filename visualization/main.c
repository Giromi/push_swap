#include "simulator.h"

int main(int ac, char *av[])
{
	int i;

	i = 0;
	if (ac == 2)
		printf("%d\n", ft_simple_atoi(av[1]));
	while (av[i++])
		printf("%s", av[i]);
	return (0);
}
