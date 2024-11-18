#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		printf("Error : cannot allocate enough memory\n");
		return (1);
	}
	if (!parsing(ac, av, data))
		return (1);
	init_win(data);
	init_map(data);
	init_img(data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->mlx_win, 6, 1L << 6, handle_mouse_move, data);
	mlx_loop_hook(data->mlx, loop_routine, data);
	mlx_loop(data->mlx);
	return (0);
}

int parsing(int ac, char **av, t_data *data)
{
	t_map_data  map_data;
	
	if (!routine_parsing(&map_data, ac, av))
	{
		printf("Error: parsing failed\n");
		return (0);
	}
	printf("parsing succeed... creating map\n");
	map_data.map_file = av[1];
	create_map_for_game(&map_data);
	display_map_data(&map_data);
	data->map_data = map_data;
	return (1);
}