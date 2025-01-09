#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!parsing(ac, av, &data))
	{
		ft_printf("Exiting program ...\n");
		return (1);
	}
	printf("MAP FILE %s\n", data.map_data.map_file);
	init_win(&data);
	init_map(&data);
	allocate_colors(&data);
	init_img(&data);
	printf("je suis la \n");
	// init_images_walls(&data);
	// WIP
	// retreive_infos_textures(&data, av);
	// retreive_infos_textures(&data.map_data, av);
	retreive_infos_textures(&data, &data.map_data, av);
	printf(" la %s \n", data.texture[0].path);
	int i = 0;
	while (i < 4)
		printf("path to texture %s \n", data.texture[i++].path);
	init_texture(&data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.mlx_win, 6, 1L << 6, handle_mouse_move, &data);
	mlx_hook(data.mlx_win, 17, 0, close_and_clean, &data);
	mlx_loop_hook(data.mlx, loop_routine, &data);
	mlx_loop(data.mlx);
	return (0);
}

int key_press(int keycode, t_data *data)
{
	if (keycode < 256 && keycode > 2)
		data->keys[keycode] = 1;
	else
	{
		if (keycode == XK_Left)
			data->keys[0] = 1;
		if (keycode == XK_Right)
			data->keys[1] = 1;
		if (keycode == XK_Escape)
			data->keys[2] = 1;
	}
	return (0);
}

int key_release(int keycode, t_data *data)
{
	if (keycode < 256 && keycode > 2)
		data->keys[keycode] = 0;
	else
	{
		if (keycode == XK_Left)
			data->keys[0] = 0;
		if (keycode == XK_Right)
			data->keys[1] = 0;
		if (keycode == XK_Escape)
			data->keys[2] = 0;
	} 
	return (0);
}
