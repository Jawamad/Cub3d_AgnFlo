#include "../inc/cub3d.h"

int	valid_pos(t_map_data *map_data, t_pos player_pos)
{
	char	c;

	c = map_data->map[(int)player_pos.y][(int)player_pos.x];
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	forward(t_map_data *map_data)
{
	t_pos	player;

	player.x = map_data->player.ppos.x;
	player.y = map_data->player.ppos.y;
	player.x += map_data->player.dirX * SPEED;
	player.y += map_data->player.dirY * SPEED;
	if (valid_pos(map_data, player))
	{
		map_data->player.ppos.x = player.x;
		map_data->player.ppos.y = player.y;
		map_data->player_pos_x = player.y;
		map_data->player_pos_y = player.x;
	}
}

void	backward(t_map_data *map_data)
{
	t_pos	player;

	player.x = map_data->player.ppos.x;
	player.y = map_data->player.ppos.y;
	player.x -= map_data->player.dirX * SPEED;
	player.y -= map_data->player.dirY * SPEED;
	if (valid_pos(map_data, player))
	{
		map_data->player.ppos.x = player.x;
		map_data->player.ppos.y = player.y;
	}
}

void	strafe_left(t_map_data *map_data)
{
	t_pos	player;

	player.x = map_data->player.ppos.x;
	player.y = map_data->player.ppos.y;
	player.x += cos(map_data->player.angle - M_PI / 2) * SPEED;
	player.y += sin(map_data->player.angle - M_PI / 2) * SPEED;
	if (valid_pos(map_data, player))
	{
		map_data->player.ppos.x = player.x;
		map_data->player.ppos.y = player.y;
	}
}

void	strafe_right(t_map_data *map_data)
{
	t_pos	player;

	player.x = map_data->player.ppos.x;
	player.y = map_data->player.ppos.y;
	player.x += cos(map_data->player.angle + M_PI / 2) * SPEED;
	player.y += sin(map_data->player.angle + M_PI / 2) * SPEED;
	if (valid_pos(map_data, player))
	{
		map_data->player.ppos.x = player.x;
		map_data->player.ppos.y = player.y;
	}
}
