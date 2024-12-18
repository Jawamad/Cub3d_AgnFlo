#include "../inc/cub3d.h"

void	clean_all(t_data *data)
{
	free_img(data);
	free_map_data(&data->map_data);
	free_wall(data->wall);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
}

void	coordswap(t_coord *a, t_coord *b)
{
	t_coord	c;

	c = *a;
	*a = *b;
	*b = c;
}
