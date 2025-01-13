#include "../inc/cub3d.h"

void	retreive_colors(char *treated_line, t_data *data)
{
	retrieve_colors_floor(treated_line, data);
	retrieve_colors_ceiling(treated_line, data);
}
void	check_F_C_exist(char *treated_line, t_data *data)
{
	if (strncmp(treated_line, "C ", 2) == 0)
		data->flag_color_c += 1;
	if (strncmp(treated_line, "F ", 2) == 0)
		data->flag_color_f += 1;
}