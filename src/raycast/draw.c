#include "../../inc/cub3d.h"

void verLine(t_data *data, int textureIndex)
{
    int y;
    int bpp = 32;
	char *img_data = data->img->addr;

    int textureWidth = data->texture[textureIndex].width;
    int textureHeight = data->texture[textureIndex].height;
	double step = (double)textureHeight / (data->verl_inf->drawend - data->verl_inf->drawstart);
    double texturePos = 0.0;
	for (y = data->verl_inf->drawstart; y < data->verl_inf->drawend; y++)
	{
        int textureY = (int)texturePos % textureHeight;
        texturePos += step;
		
        unsigned int pixel = data->wall[textureIndex][textureY * textureWidth + data->verl_inf->texturex];
        unsigned char red = (pixel >> 16) & 0xFF;
        unsigned char green = (pixel >> 8) & 0xFF;
        unsigned char blue = pixel & 0xFF;
        int pixel_index = (data->verl_inf->x + y * data->screenWidth) * (bpp / 8);
        
		img_data[pixel_index + 2] = red;
		img_data[pixel_index + 1] = green;
		img_data[pixel_index] = blue;
    }
}

void draw_ceiling(t_data *data)
{
    int y;
    int bpp;
    char *img_data;
	int pixel_index;
    
	img_data = data->img->addr;
    bpp = 32;
	y = 0;
    while (y < data->verl_inf->drawstart)
    {
        pixel_index = (data->verl_inf->x + y * data->screenWidth) * (bpp / 8);
        img_data[pixel_index] =  data->colors_floor->r;
        img_data[pixel_index + 1] =  data->colors_floor->g;
        img_data[pixel_index + 2] =  data->colors_floor->b;
        y++;
    }
}


void draw_floor(t_data *data)
{
    int y;
    int bpp;
    char *img_data;
	int pixel_index;

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
