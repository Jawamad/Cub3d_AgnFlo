#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	(void)ac;
	(void)av;
	data = malloc(sizeof(t_data));
	if (!data)
	{
		fprintf(stderr, "Erreur : échec de l'allocation mémoire pour data\n");
		return (1);
	}
	init_win(data);
	init_map(data);
	init_img(data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->mlx_win, 6, 1L << 6, handle_mouse_move, data);
	mlx_loop_hook(data->mlx, loop_routine, data);
	mlx_loop(data->mlx);
	return (0);
}