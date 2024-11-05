#include "../inc/cub3d.h"

int handle_keypress(int keycode, t_data *data)
{
	data->key_pressed = 1;
	data->keycode = keycode;
	return (0);
}

int handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == data->keycode)
		data->key_pressed = 1;
	return (0);
}

int	loop_routine(t_data *data)
{
	if (data->key_pressed == 1)
	{
		printf("test\n");
		action_key(data);
	}
	parse_map(data);
	set_player(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img_ptr, 0, 0);
	return (1);
}

void action_key(t_data *data)
{
	if (data->keycode == 105)
		data->map_data.player.angle -= 0.0873;

    // S'assurer que l'angle reste entre 0 et 2π pour éviter les débordements
    if (data->map_data.player.angle < 0)
        data->map_data.player.angle += 2 * M_PI;
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
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_keypress, &data);// Événement KeyPress
	mlx_hook(data->mlx_win, 3, 1L << 1, handle_keyrelease, &data);
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