#include "../../inc/cub3d.h"

void verLine(int x, int drawStart, int drawEnd, t_data *data, int textureIndex, int textureX)
{
    int y;
    int bpp = 32;
	char *img_data = data->img->addr;

    int textureWidth = data->texture[textureIndex].width;
    int textureHeight = data->texture[textureIndex].height;
    double step = (double)textureHeight / data->line_height;
    //double step = (double)textureHeight / (drawEnd - drawStart);
    double texturePos = 0.0;
    // int textureX = (x % textureWidth);
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
    int bpp = 32;
    char *img_data = data->img->addr;
    unsigned char r;
    unsigned char g;
    unsigned char b;

    r = 0;  
    g = 255; 
    b = 0;

    y = 0;
	
    while (y < drawStart)
    {
        int pixel_index = (x + y * data->screenWidth) * (bpp / 8);
        img_data[pixel_index] = r;
        img_data[pixel_index + 1] = g;
        img_data[pixel_index + 2] = b;
        y++;
    }
}


void draw_floor(int x, int drawEnd, t_data *data)
{
    int y;
    int bpp = 32;
    char *img_data = data->img->addr;
    unsigned char r;
    unsigned char g;
    unsigned char b;

    r = 0;  
    g = 255; 
    b = 0;

    y = drawEnd;
    while (y < data->screenHeight)
    {
        int pixel_index = (x + y * data->screenWidth) * (bpp / 8);
        img_data[pixel_index] = r;
        img_data[pixel_index + 1] = g;
        img_data[pixel_index + 2] = b;
        y++;
    }
}
