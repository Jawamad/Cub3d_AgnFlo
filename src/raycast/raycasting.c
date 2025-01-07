#include "../../inc/cub3d.h"

void calc_deltadist(t_data *data, t_dpos *deltadist)
{
    if (data->raydir.x == 0)
        deltadist->x = 1e30;
    else
        deltadist->x = fabs(1 / data->raydir.x);
    
    if (data->raydir.y == 0)
        deltadist->y = 1e30;
    else
        deltadist->y = fabs(1 / data->raydir.y);
}


void	calc_sidedist(t_data *data, t_dpos *sidedist, t_coord *map, t_dpos deltadist)
{
	if (data->raydir.x < 0)
		sidedist->x = (data->map_data.player_pos_x - map->x) * deltadist.x;
	else
		sidedist->x = (map->x + 1.0 - data->map_data.player_pos_x) * deltadist.x;
	if (data->raydir.y < 0)
		sidedist->y = (data->map_data.player_pos_y - map->y) * deltadist.y;
	else
		sidedist->y = (map->y + 1.0 - data->map_data.player_pos_y) * deltadist.y;
}

void init_step(t_data *data, t_coord *step)
{
    if (data->raydir.x < 0)
        step->x = -1;
    else
        step->x = 1;

    if (data->raydir.y < 0)
        step->y = -1;
    else
        step->y = 1;
}

void	init_perp_wall_d(int side, double *perp_wall_d, t_dpos sidedist, t_dpos deltadist)
{
	if (side == 0)
		*perp_wall_d = (sidedist.x - deltadist.x);
	else
		*perp_wall_d = (sidedist.y - deltadist.y);
}

void	calc_dist(t_data *data, t_coord *map, int *side, double *perp_wall_d)
{
	t_dpos	sidedist;
	t_dpos	deltadist;
	t_coord	step;
	int		hit;

	calc_deltadist(data, &deltadist);
	init_step(data, &step);
	calc_sidedist(data, &sidedist, map, deltadist);

	hit = 0;
	while (hit == 0) 
	{
		if (sidedist.x < sidedist.y) {
			sidedist.x += deltadist.x;
			map->x += step.x;
			*side = 0;
		} else {
			sidedist.y += deltadist.y;
			map->y += step.y;
			*side = 1;
		}
		if (!valid_pos(&data->map_data, map->y, map->x))
			hit = 1;
	}
	init_perp_wall_d(*side, perp_wall_d, sidedist, deltadist);
}

void	draw_define(double perp_wall_d, int *drawstart, int *drawend)
{
	int	lineHeight;

	lineHeight = (int)(SC_HEIGHT / perp_wall_d);
	*drawstart = -lineHeight / 2 + SC_HEIGHT / 2;
	if (*drawstart < 0)
		*drawstart = 0;
	*drawend = lineHeight / 2 + SC_HEIGHT / 2;
	if (*drawend >= SC_HEIGHT)
		*drawend = SC_HEIGHT - 1;
}

void	calc_wallx(double *wallx, t_data *data, int side, double perp_wall_d)
{
	if (side == 0)
		*wallx = (data->map_data.player_pos_y + perp_wall_d * data->raydir.y);
	else
		*wallx = (data->map_data.player_pos_x + perp_wall_d * data->raydir.x);
	*wallx -= floor(*wallx);
}

int	get_textureindex(t_data *data, int side)
{
	if (side == 0) // EAST or WEST
	{
		if (data->raydir.x > 0)
			return (0);
		else	
			return (1);
	}
	else
	{
		if (data->raydir.y > 0)
			return (2);
		else
			return (3);
	}
}
// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------

// int	get_textureindex(t_data *data, int side)
// {
// 	if (side == 0) // EAST or WEST
// 		return (data->raydir.x > 0 ? 0 : 1); // EAST: 0, WEST: 1
// 	else // NORTH or SOUTH
// 		return (data->raydir.y > 0 ? 2 : 3); // NORTH: 2, SOUTH: 3
// }

// int	get_texturex(t_data *data, double wallx, int side, double perp_wall_d)
int	get_texturex(t_data *data, double wallx, int side)
{
	int	texture_width;
	int	texturex;

	texture_width = data->texture[get_textureindex(data, side)].width;

	texturex = (int)(wallx * texture_width);

	if ((side == 0 && data->raydir.x > 0) || (side == 1 && data->raydir.y < 0))
		texturex = texture_width - texturex - 1;

	return (texturex);
	
}

int	raycast(t_data *data, int *drawstart, int *drawend, int *texturex)
{
	double	perp_wall_d;
	int		side;
	t_coord	map;
	double	wallx;

	map.x = (int)data->map_data.player_pos_x;
	map.y = (int)data->map_data.player_pos_y;
	calc_dist(data, &map, &side, &perp_wall_d);
	draw_define(perp_wall_d, drawstart, drawend);
	calc_wallx(&wallx, data, side, perp_wall_d);
	*texturex = get_texturex(data, wallx, side);
	return (side);
}

void	init_raydir(t_data *data, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SC_WIDTH - 1;
	data->raydir.x = data->map_data.player.dirX + data->map_data.player.planeX * camera_x;
	data->raydir.y = data->map_data.player.dirY + data->map_data.player.planeY * camera_x; 
}

void	cast_rays_and_render(t_data *data)
{
	int	x;
	int	drawstart;
	int	drawend;
	int	texturex;
	int	side;

	x = 0;
	while (x < SC_WIDTH) 
	{
		init_raydir(data, x);
		side = raycast(data, &drawstart, &drawend, &texturex);
		verLine(x, drawstart, drawend, data, get_textureindex(data, side), texturex);
		draw_ceiling(x, drawstart, data);
		draw_floor(x, drawend, data);
		x++;
	}
}


