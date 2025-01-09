/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:39:48 by agtshiba          #+#    #+#             */
/*   Updated: 2025/01/08 15:40:25 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_raydir(t_data *data, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SC_WIDTH - 1;
	data->raydir.x = data->map_data.player.dirX + data->map_data.player.planeX
		* camera_x;
	data->raydir.y = data->map_data.player.dirY + data->map_data.player.planeY
		* camera_x;
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
		verLine(x, drawstart, drawend, data, get_textureindex(data, side),
			texturex);
		draw_ceiling(x, drawstart, data);
		draw_floor(x, drawend, data);
		x++;
	}
}
