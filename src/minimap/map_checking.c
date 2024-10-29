#include "../../inc/cub3d.h"

void	parse_map(t_data *data)
{
	t_coord	checker;
	t_coord	pen;
	int		tile;

	tile = TILE;
	checker = create_coord(0,0);
	pen = create_coord(tile, tile);
	while (checker.y <= data->map_data.nb_row)
	{
		while (checker.x <= data->map_data.nb_column)
		{
			data->map_data.map[checker.y][checker.x];
			draw_tile(data->map_data.map[checker.y][checker.x], &pen);
			checker.x++;
		}
		checker.y++;
	}
}