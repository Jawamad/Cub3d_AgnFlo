#include "../../inc/cub3d.h"

int	parse_map(t_data *data)
{
	t_coord	checker;
	t_coord	pen;
	int		tile;

	tile = TILE;
	checker = create_coord(0,0);
	pen = create_coord(tile, tile);
	while (checker.y < data->map_data.height)
	{
		while (checker.x < data->map_data.width)
		{
			printf("x: %d, y: %d\n", pen.x, pen.y);
			draw_tile(data, data->map_data.map[checker.y][checker.x], &pen);
			pen.x += tile;
			checker.x++;
		}
		pen.x = tile;
		pen.y += tile;
		checker.x = 0;
		checker.y++;
	}
	return (1);
}

void	draw_tile(t_data *data, char c, t_coord *pen)
{
	int	tile;
	t_coord	limit;

	tile = TILE;
	limit = create_coord(pen->x + tile, pen->y + tile);
	while (pen->y < limit.y)
	{
		while (pen->x < limit.x)
		{
			if (is_onmap(c))
				mlx_pixel_put(data->mlx, data->mlx_win, pen->x, pen->y, select_color(c));
			pen->x++;
		}
		pen->x = limit.x - tile;
		pen->y++;
	}
	pen->y = limit.y - tile;
}

int	select_color(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0xFF0000);
	else if (c == '1')
		return (0x00FF00);
	else
		return (0xFFFFFF);
}

int is_onmap(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return(1);
	return (0);
}