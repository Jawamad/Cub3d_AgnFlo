#include "../inc/cub3d.h"

void	retreive_colors(char *treated_line, t_data *data)
{
	retrieve_colors_floor(treated_line, data);
	retrieve_colors_ceiling(treated_line, data);
}

