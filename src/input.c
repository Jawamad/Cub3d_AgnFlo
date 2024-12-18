#include "../inc/cub3d.h"

int	handle_keypress(int keycode, t_data *data)
{
	data->key_pressed = 1;
	data->keycode = keycode;
	return (0);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	(void) y;
	if (x > data->mouse_x)
		turn_right(&data->map_data);
	else if (x < data->mouse_x)
		turn_left(&data->map_data);
	mlx_mouse_move(data->mlx, data->mlx_win, SC_WIDTH / 2, SC_HEIGHT / 2);
	return (1);
}

void	action_key(t_data *data)
{
	if (data->keycode == 65307)
		close_and_clean(data);
	else if (data->keycode == 65361)
		turn_left(&data->map_data);
	else if (data->keycode == 65363)
		turn_right(&data->map_data);
	else if (data->keycode == 119)
		forward(&data->map_data);
	else if (data->keycode == 115)
		backward(&data->map_data);
	else if (data->keycode == 97)
		strafe_left(&data->map_data);
	else if (data->keycode == 100)
		strafe_right(&data->map_data);
}

int	close_and_clean(t_data *data)
{
	clean_all(data);
	exit(1);
	return (0);
}
