#include "../inc/cub3d.h"


int	main(int ac, char **av)
{
	// t_data	data;
	t_map_data  map_data;
	
	//int i = 0;
	(void)ac;

	/* if (ac != 2)
		ft_error(0);
	check_exten(av[1]);
	parsing(av, &data);
	*/
	if (!check_extension_file_name(av[1]))
    {
        ft_printf("Error: invalid file extension\n");
        return (0);
    }

	map_data.map_file = av[2];

    // if (!does_file_exist(map_data.map_file))
    //     return (0);

	// if (!create_map_for_game(&data, &map_data))
	// 	return (0);

	/*
	printf("NO : %s\n", data.map_data.no);
	printf("SO : %s\n", data.map_data.so);
	printf("WE : %s\n", data.map_data.we);
	printf("EA : %s\n", data.map_data.ea);
	printf("C : %s\n", data.map_data.cc);
	printf("F : %s\n", data.map_data.cf);
	while (i < 14)
	{
		printf("ligne %d : %s\n", i, data.map_data.map[i]);
		i++;
	} */
	// init_win(&data);
	// init_map(&data);
	// mlx_loop_hook(data.mlx, set_minimap, &data);
	// mlx_loop(data.mlx);
	// if (data.map_data.map[0] != NULL)
	// 	free_array(data.map_data.map);
	// free_char_option(&data);

	//return (0);

	//display_map(&data);
	//mlx_key_hook(data.mlx_win, handle_events, &data);
	//mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	//mlx_loop(data.mlx);
}