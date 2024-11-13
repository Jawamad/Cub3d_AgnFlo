#include "../inc/cub3d.h"

void	turn_left(t_map_data *map_data)
{
	map_data->player.angle -= 0.0873;
	if (map_data->player.angle < 0)
		map_data->player.angle = 2 * M_PI;
}

void	turn_right(t_map_data *map_data)
{
	map_data->player.angle += 0.0873;
	if (map_data->player.angle > 2 * M_PI)
		map_data->player.angle = 0;
}
