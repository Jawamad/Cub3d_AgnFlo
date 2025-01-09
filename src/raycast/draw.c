#include "../../inc/cub3d.h"

void verLine(int x, int drawStart, int drawEnd, t_data *data, int textureIndex, int textureX)
{
    int y;
    int bpp = 32;
	char *img_data = data->img->addr;

    int textureWidth = data->texture[textureIndex].width;
    int textureHeight = data->texture[textureIndex].height;
    double step = (double)textureHeight / (drawEnd - drawStart);
    double texturePos = 0.0;
    for (y = drawStart; y < drawEnd; y++)
	{
        int textureY = (int)texturePos % textureHeight;
        texturePos += step;
		
        unsigned int pixel = data->wall[textureIndex][textureY * textureWidth + textureX];
        unsigned char red = (pixel >> 16) & 0xFF;
        unsigned char green = (pixel >> 8) & 0xFF;
        unsigned char blue = pixel & 0xFF;
        int pixel_index = (x + y * data->screenWidth) * (bpp / 8);
        
		img_data[pixel_index + 2] = red;
		img_data[pixel_index + 1] = green;
		img_data[pixel_index] = blue;
    }
}

void draw_ceiling(int x, int drawStart, t_data *data)
{
    int y;
    int bpp;
    char *img_data;
	int pixel_index;
    
	img_data = data->img->addr;
    bpp = 32;
	y = 0;
    while (y < drawStart)
    {
        pixel_index = (x + y * data->screenWidth) * (bpp / 8);
        img_data[pixel_index] =  data->colors_floor->r;
        img_data[pixel_index + 1] =  data->colors_floor->g;
        img_data[pixel_index + 2] =  data->colors_floor->b;
        y++;
    }
}


void draw_floor(int x, int drawEnd, t_data *data)
{
    int y;
    int bpp;
    char *img_data;
	int pixel_index;

	img_data = data->img->addr;
	bpp = 32;
    y = drawEnd;
    while (y < data->screenHeight)
    {
        pixel_index = (x + y * data->screenWidth) * (bpp / 8);
        img_data[pixel_index] = data->colors_ceiling->r;
        img_data[pixel_index + 1] = data->colors_ceiling->g;
        img_data[pixel_index + 2] = data->colors_ceiling->b;
        y++;
    }
}
