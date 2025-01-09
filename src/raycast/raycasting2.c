/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:15:25 by agtshiba          #+#    #+#             */
/*   Updated: 2025/01/08 15:39:41 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_define(double perp_wall_d, int *drawstart, int *drawend)
{
	int	lineheight;

	lineheight = (int)(SC_HEIGHT / perp_wall_d);
	*drawstart = -lineheight / 2 + SC_HEIGHT / 2;
	if (*drawstart < 0)
		*drawstart = 0;
	*drawend = lineheight / 2 + SC_HEIGHT / 2;
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
	if (side == 0)
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
