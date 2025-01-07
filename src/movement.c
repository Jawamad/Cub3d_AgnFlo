#include "../inc/cub3d.h"

int	valid_pos(t_map_data *map_data, int x, int y)
{
	char	c;

	if (x < 0 || x >= map_data->width || y < 0 || y >= map_data->height)
        return (0);  // En dehors des limites de la carte

	c = map_data->map[y][x];
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	forward(t_map_data *map_data)
{
	t_pos	player;

	player.x = map_data->player_pos_x;
	player.y = map_data->player_pos_y;
	player.x += map_data->player.dirX * SPEED;
	player.y += map_data->player.dirY * SPEED;
	if (valid_pos(map_data, (int)player.y, (int)player.x))
	{
		map_data->player.ppos.x = player.y;
		map_data->player.ppos.y = player.x;
		map_data->player_pos_x = player.x;
		map_data->player_pos_y = player.y;
	}
}

void	backward(t_map_data *map_data)
{
	t_pos	player;

	player.x = map_data->player_pos_x;
	player.y = map_data->player_pos_y;
	player.x -= map_data->player.dirX * SPEED;
	player.y -= map_data->player.dirY * SPEED;
	if (valid_pos(map_data, (int)player.y, (int)player.x))
	{
		map_data->player.ppos.x = player.y;
		map_data->player.ppos.y = player.x;
		map_data->player_pos_x = player.x;
		map_data->player_pos_y = player.y;
	}
}

void	strafe_left(t_map_data *map_data)
{
	t_pos	player;

	player.x = map_data->player.ppos.x;
	player.y = map_data->player.ppos.y;
	player.x += cos(map_data->player.angle - M_PI / 2) * SPEED;
	player.y += sin(map_data->player.angle - M_PI / 2) * SPEED;
	if (valid_pos(map_data, (int)player.x, (int)player.y))
	{
		map_data->player.ppos.x = player.x;
		map_data->player.ppos.y = player.y;
		map_data->player_pos_x = player.y;
		map_data->player_pos_y = player.x;
	}
}

void	strafe_right(t_map_data *map_data)
{
	t_pos	player;

	player.x = map_data->player.ppos.x;
	player.y = map_data->player.ppos.y;
	player.x += cos(map_data->player.angle + M_PI / 2) * SPEED;
	player.y += sin(map_data->player.angle + M_PI / 2) * SPEED;
	if (valid_pos(map_data, (int)player.x, (int)player.y))
	{
		map_data->player.ppos.x = player.x;
		map_data->player.ppos.y = player.y;
		map_data->player_pos_x = player.y;
		map_data->player_pos_y = player.x;
	}
}
