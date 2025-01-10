#include "../../inc/cub3d.h"

void	init_verline(t_data *data, int textureindex)
{
	data->verl_inf->step = (double)data->texture[textureindex].height
		/ (data->verl_inf->drawend - data->verl_inf->drawstart);
	data->verl_inf->texturePos = 0.0;
	data->verl_inf->textureY = 0;
	data->verl_inf->pixel = 0;
	data->verl_inf->red = 0;
	data->verl_inf->green = 0;
	data->verl_inf->blue = 0;
}

void	verline(t_data *data, int textindex)
{
	int	y;
	int	pixel_index;

	init_verline(data, textindex);
	y = data->verl_inf->drawstart;
	while (y < data->verl_inf->drawend)
	{
		data->verl_inf->textureY = (int)data->verl_inf->texturePos
			% data->texture[textindex].height;
		data->verl_inf->texturePos += data->verl_inf->step;
		data->verl_inf->pixel = data->wall[textindex][data->verl_inf->textureY
			* data->texture[textindex].width + data->verl_inf->texturex];
		data->verl_inf->red = (data->verl_inf->pixel >> 16) & 0xFF;
		data->verl_inf->green = (data->verl_inf->pixel >> 8) & 0xFF;
		data->verl_inf->blue = data->verl_inf->pixel & 0xFF;
		pixel_index = (data->verl_inf->x + y * data->screenWidth) * (32 / 8);
		data->img->addr[pixel_index + 2] = data->verl_inf->red;
		data->img->addr[pixel_index + 1] = data->verl_inf->green;
		data->img->addr[pixel_index] = data->verl_inf->blue;
		y++;
	}
}

void	draw_ceiling(t_data *data)
{
	int		y;
	int		bpp;
	char	*img_data;
	int		pixel_index;

	img_data = data->img->addr;
	bpp = 32;
	y = 0;
	while (y < data->verl_inf->drawstart)
	{
		pixel_index = (data->verl_inf->x + y * data->screenWidth) * (bpp / 8);
		img_data[pixel_index] = data->colors_floor->r;
		img_data[pixel_index + 1] = data->colors_floor->g;
		img_data[pixel_index + 2] = data->colors_floor->b;
		y++;
	}
}

void	draw_floor(t_data *data)
{
	int		y;
	int		bpp;
	char	*img_data;
	int		pixel_index;

	img_data = data->img->addr;
	bpp = 32;
	y = data->verl_inf->drawend;
	while (y < data->screenHeight)
	{
		pixel_index = (data->verl_inf->x + y * data->screenWidth) * (bpp / 8);
		img_data[pixel_index] = data->colors_ceiling->r;
		img_data[pixel_index + 1] = data->colors_ceiling->g;
		img_data[pixel_index + 2] = data->colors_ceiling->b;
		y++;
	}
}
