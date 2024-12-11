#include "../../inc/cub3d.h"

t_pos	search_player(t_data *data)
{
	t_pos	pos;

	pos = create_pos(0, 0);
	while (data->map_data.map[(int)pos.y][(int)pos.x])
	{
		if (!is_player_mmap(data->map_data.map[(int)pos.y][(int)pos.x]))
			return (pos);
		pos.x++;
		if (pos.x >= data->map_data.width)
		{
			pos.x = 0;
			pos.y++;
		}
	}
	return (pos);
}

void	set_player(t_data *data)
{
	t_arrow	player_a;

	set_arrow_point(&data->map_data.player, &player_a);
	fill_triangle(data, player_a.head, player_a.left, player_a.right);
	draw_line(data, player_a.head, player_a.left);
	draw_line(data, player_a.left, player_a.right);
	draw_line(data, player_a.head, player_a.right);
}

void	set_arrow_point(t_player *player, t_arrow *arrow)
{
	float	arr_len;
	float	arr_width;

	arr_len = TILE / 2;
	arr_width = TILE / 2;
	arrow->head.x = round(((player->ppos.x * TILE) + TILE)
			+ cos(player->angle) * arr_len);
	arrow->head.y = round(((player->ppos.y * TILE) + TILE)
			+ sin(player->angle) * arr_len);
	arrow->left.x = round(((player->ppos.x * TILE) + TILE)
			+ cos(player->angle + M_PI / 2) * arr_width);
	arrow->left.y = round(((player->ppos.y * TILE) + TILE)
			+ sin(player->angle + M_PI / 2) * arr_width);
	arrow->right.x = round(((player->ppos.x * TILE) + TILE)
			+ cos(player->angle - M_PI / 2) * arr_width);
	arrow->right.y = round(((player->ppos.y * TILE) + TILE)
			+ sin(player->angle - M_PI / 2) * arr_width);
}

int	is_player_mmap(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (1);
}
