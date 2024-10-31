#include "../inc/cub3d.h"



int	loop_routine(t_data *data)
{
	parse_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img_ptr, 0, 0);
	return (1);
}


int	main(int ac, char **av)
{
	t_data	*data;
	//int i = 0;
	(void)ac;
	(void)av;

	/* if (ac != 2)
		ft_error(0);
	check_exten(av[1]);
	parsing(av, &data);


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


	// Allocation explicite de data
	data = malloc(sizeof(t_data));
	if (!data)
	{
		fprintf(stderr, "Erreur : échec de l'allocation mémoire pour data\n");
		return (1);
	}
	init_win(data);
	init_map(data);
	init_img(data);
	mlx_loop_hook(data->mlx, loop_routine, data);
	mlx_loop(data->mlx);
	if (data->map_data.map[0] != NULL)
		free_array(data->map_data.map);
	//free_char_option(&data);


	return (0);





	//display_map(&data);
	//mlx_key_hook(data.mlx_win, handle_events, &data);
	//mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	//mlx_loop(data.mlx);
}