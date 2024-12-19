#include "../inc/cub3d.h"

void	turn_left(t_map_data *map_data)
{
	rotate(&map_data->player, ROT_SPEED, 1);
	map_data->player.angle = atan2(map_data->player.dirX,
			map_data->player.dirY);
}

void	turn_right(t_map_data *map_data)
{
	rotate(&map_data->player, ROT_SPEED, -1);
	map_data->player.angle = atan2(map_data->player.dirX,
			map_data->player.dirY);
}

void	rotate(t_player *data, double rotSpeed, int direction)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dirX;
	old_plane_x = data->planeX;
	data->dirX = data->dirX * cos(rotSpeed * direction)
		- data->dirY * sin(rotSpeed * direction);
	data->dirY = old_dir_x * sin(rotSpeed * direction)
		+ data->dirY * cos(rotSpeed * direction);
	data->planeX = data->planeX * cos(rotSpeed * direction)
		- data->planeY * sin(rotSpeed * direction);
	data->planeY = old_plane_x * sin(rotSpeed * direction)
		+ data->planeY * cos(rotSpeed * direction);
	data->angle = atan2(data->dirX, data->dirY);
}
