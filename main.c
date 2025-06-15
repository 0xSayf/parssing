#include "parsing.h"

int	main(int ac, char **av)
{
	t_map *parse;

	if (ac != 2)
		return (0);
	char *path = av[1];
	if (!ft_check_dot(path))
	{
		printf("Invalide file format\n");
		return (0);
	}
	else
	{
		parse = parse_map_file(path);

	}
	// while(1);
}