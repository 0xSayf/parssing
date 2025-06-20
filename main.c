#include "include/cub3d.h"

int	main(int ac , char **argv)
{
	t_game	game;
	t_map	*parse;

	if (!ft_check_dot(argv[1]))
		return (EXIT_FAILURE);
	parse = parse_map_file(argv[1]);
	if(!parse)
		return (EXIT_FAILURE);
	game.map_data = parse;
	if (!init_game(&game))
		return (EXIT_FAILURE);
	game_loop(&game);
	//TODO clean_up(&game);
	return (EXIT_SUCCESS);
}