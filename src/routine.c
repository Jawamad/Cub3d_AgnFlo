#include "../inc/cub3d.h"

int	loop_routine(t_data *data)
{
	if (data->key_pressed == 1)
	{
		action_key(data);
		data->key_pressed = 0;
	}
	parse_mmap(data);
	set_player(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img_ptr, 0, 0);
	return (1);
}