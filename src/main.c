#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!parsing(ac, av, &data))
	{
		ft_printf("Exiting program ...\n");
		return (1);
	}
	init_win(&data);
	init_map(&data);
	init_img(&data);
	init_texture(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.mlx_win, 6, 1L << 6, handle_mouse_move, &data);
	mlx_hook(data.mlx_win, 17, 0, close_and_clean, &data);
	mlx_loop_hook(data.mlx, loop_routine, &data);
	mlx_loop(data.mlx);
	return (0);
}

int parsing(int ac, char **av, t_data *data)
{
	t_map_data  map_data;

	if (!routine_parsing(&map_data, ac, av))
	{
		ft_printf("Error: parsing failed\n");
		return (0);
	}
	ft_printf("parsing succeed... creating map\n");
	map_data.map_file = av[1];
	create_map_for_game(&map_data);
	display_map_data(&map_data);
	if (!too_many_player(map_data))
	{
		free_map_data(&map_data);
		ft_printf("There is less or more than one player entity on the map.\n");
		ft_printf("please verify map settings.\n");
		return (0);
	}
	data->map_data = map_data;
	return (1);
}

int too_many_player(t_map_data map_data)
{
	int	i;
	int	j;
	int	pcount;

	i = 0;
	pcount = 0;
	if (map_data.map == NULL)
		return (0);
	while (map_data.map[i])
	{
		j = 0;
		while(map_data.map[i][j])
		{
			if (map_data.map[i][j] == '\0')
				break;
			if (!is_player_mmap(map_data.map[i][j]))
				pcount++;
			j++;
		}
		i++;
	}
	if (pcount != 1)
		return (0);
	return (1);
}