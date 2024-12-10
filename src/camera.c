#include "../inc/cub3d.h"

void	turn_left(t_map_data *map_data)
{
	rotate(&map_data->player, 0.01, 1);
}

void	turn_right(t_map_data *map_data)
{
	rotate(&map_data->player, 0.01, -1);
	map_data->player.angle = atan2(map_data->player.dirX, map_data->player.dirY);
}

void rotate(t_player *data, double rotSpeed, int direction) {
    double oldDirX = data->dirX;
    double oldPlaneX = data->planeX;

    data->dirX = data->dirX * cos(rotSpeed * direction) - data->dirY * sin(rotSpeed * direction);
    data->dirY = oldDirX * sin(rotSpeed * direction) + data->dirY * cos(rotSpeed * direction);

    data->planeX = data->planeX * cos(rotSpeed * direction) - data->planeY * sin(rotSpeed * direction);
    data->planeY = oldPlaneX * sin(rotSpeed * direction) + data->planeY * cos(rotSpeed * direction);
	data->angle = atan2(data->dirX, data->dirY);
}