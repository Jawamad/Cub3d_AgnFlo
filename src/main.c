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
