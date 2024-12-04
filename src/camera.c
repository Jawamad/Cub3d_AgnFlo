#include "../inc/cub3d.h"

void	turn_left(t_map_data *map_data)
{
	map_data->player.angle -= 0.0873;
	if (map_data->player.angle < 0)
		map_data->player.angle = 2 * M_PI;
	rotate(&map_data->player, 0.01, 1);
}

void	turn_right(t_map_data *map_data)
{
	map_data->player.angle += 0.0873;
	if (map_data->player.angle > 2 * M_PI)
		map_data->player.angle = 0;
	rotate(&map_data->player, 0.01, -1);
}

void rotate(t_player *data, double rotSpeed, int direction) {
    double oldDirX = data->dirX;
    double oldPlaneX = data->planeX;

    data->dirX = data->dirX * cos(rotSpeed * direction) - data->dirY * sin(rotSpeed * direction);
    data->dirY = oldDirX * sin(rotSpeed * direction) + data->dirY * cos(rotSpeed * direction);

    data->planeX = data->planeX * cos(rotSpeed * direction) - data->planeY * sin(rotSpeed * direction);
    data->planeY = oldPlaneX * sin(rotSpeed * direction) + data->planeY * cos(rotSpeed * direction);
}