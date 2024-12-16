#include "../../inc/cub3d.h"

void cast_rays_and_render(t_data *data)
{
    int w = data->screenWidth;
    int h = data->screenHeight;
    int x = 0;
    while (x < w) 
    {
        double cameraX = 2 * x / (double)w - 1;
        double rayDirX = data->map_data.player.dirX + (data->map_data.player.planeX) * cameraX;
        double rayDirY = data->map_data.player.dirY + (data->map_data.player.planeY) * cameraX;
        int mapX = (int)(data->map_data.player_pos_x);
        int mapY = (int)(data->map_data.player_pos_y);
        double sideDistX;
        double sideDistY;
        double deltaDistX;
        double deltaDistY;
        deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;
        int stepX;
        int stepY;
        int hit = 0;
        int side;

        // Calculer le pas et la distance
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = ((data->map_data.player_pos_x) - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - (data->map_data.player_pos_x)) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = ((data->map_data.player_pos_y) - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - (data->map_data.player_pos_y)) * deltaDistY;
        }

        // DDA
       while (hit == 0) 
        {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (!valid_pos(&data->map_data, mapY, mapX)) {
                hit = 1;
            }
        }
        if (side == 0) {
            perpWallDist = (sideDistX - deltaDistX);
        } else {
            perpWallDist = (sideDistY - deltaDistY);
        }
        int lineHeight = (int)(h / perpWallDist);
        int drawStart = -lineHeight / 2 + h / 2;
        if (drawStart < 0) {
            drawStart = 0;
        }
        int drawEnd = lineHeight / 2 + h / 2;
        if (drawEnd >= h) {
            drawEnd = h - 1;
        }

         // Déterminer la couleur
        unsigned char r, g, b;

		if (data->map_data.map[mapX][mapY] == 1){
			r = 255; g = 0; b = 0;   // Rouge
		} else if (data->map_data.map[mapX][mapY] == 2) {
			r = 0;   g = 255; b = 0;   // Vert
		} else if (data->map_data.map[mapX][mapY] == 3) {
			r = 0;   g = 0;   b = 255; // Bleu
		} else if (data->map_data.map[mapX][mapY] == 4) {
			r = 255; g = 255; b = 255; // Blanc
		} else {
			r = 255; g = 255; b = 0;   // Jaune (par défaut)
		}

        // Assombrir la couleur si le côté est 1
        if (side == 1) {
            r /= 2;
            g /= 2;
            b /= 2;
        }

		double wallX; 
        if (side == 0) {
            wallX = data->map_data.player_pos_y + perpWallDist * rayDirY;
        } else {
            wallX = data->map_data.player_pos_x + perpWallDist * rayDirX;
        }
        wallX -= floor(wallX);
        int textureIndex = 0;

        // Calculate the textureX coordinate
        int textureWidth = data->texture[textureIndex].width;
        int textureX = (int)(wallX * textureWidth);
        if (side == 0 && rayDirX > 0) textureX = textureWidth - textureX - 1;
        if (side == 1 && rayDirY < 0) textureX = textureWidth - textureX - 1;

        verLine(x, drawStart, drawEnd, data, textureIndex, textureX);		
        draw_ceiling(x, drawStart, data);
        draw_floor(x, drawEnd, data);


        x++;
    }
}

// #include "../../inc/cub3d.h"

// void cast_rays_and_render(t_data *data)
// {
//     int w = data->screenWidth;
//     int h = data->screenHeight;
//     int x = 0;
//     while (x < w) 
//     {
//         double cameraX = 2 * x / (double)w - 1;
//         double rayDirX = data->map_data.player.dirX + (data->map_data.player.planeX) * cameraX;
//         double rayDirY = data->map_data.player.dirY + (data->map_data.player.planeY) * cameraX;
//         int mapX = (int)(data->map_data.player_pos_x);
//         int mapY = (int)(data->map_data.player_pos_y);
//         double sideDistX;
//         double sideDistY;
//         double deltaDistX;
//         double deltaDistY;
//         deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
//         deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
//         double perpWallDist;
//         int stepX;
//         int stepY;
//         int hit = 0;
//         int side;

//         // Calculer le pas et la distance
//         if (rayDirX < 0) {
//             stepX = -1;
//             sideDistX = ((data->map_data.player_pos_x) - mapX) * deltaDistX;
//         } else {
//             stepX = 1;
//             sideDistX = (mapX + 1.0 - (data->map_data.player_pos_x)) * deltaDistX;
//         }
//         if (rayDirY < 0) {
//             stepY = -1;
//             sideDistY = ((data->map_data.player_pos_y) - mapY) * deltaDistY;
//         } else {
//             stepY = 1;
//             sideDistY = (mapY + 1.0 - (data->map_data.player_pos_y)) * deltaDistY;
//         }

//         // DDA
//         while (hit == 0) 
//         {
//             if (sideDistX < sideDistY) {
//                 sideDistX += deltaDistX;
//                 mapX += stepX;
//                 side = 0;
//             } else {
//                 sideDistY += deltaDistY;
//                 mapY += stepY;
//                 side = 1;
//             }
//             if (!valid_pos(&data->map_data, mapY, mapX)) {
//                 hit = 1;
//             }
//         }
//         // Calculer la distance du mur
//         if (side == 0) {
//             perpWallDist = (sideDistX - deltaDistX);
//         } else {
//             perpWallDist = (sideDistY - deltaDistY);
//         }
//         int lineHeight = (int)(h / perpWallDist);
//         int drawStart = -lineHeight / 2 + h / 2;
//         if (drawStart < 0) {
//             drawStart = 0;
//         }
//         int drawEnd = lineHeight / 2 + h / 2;
//         if (drawEnd >= h) {
//             drawEnd = h - 1;
//         }

//          // Déterminer la couleur
//         unsigned char r, g, b;

// 		if (data->map_data.map[mapX][mapY] == 1){
// 			r = 255; g = 0; b = 0;   // Rouge
// 		} else if (data->map_data.map[mapX][mapY] == 2) {
// 			r = 0;   g = 255; b = 0;   // Vert
// 		} else if (data->map_data.map[mapX][mapY] == 3) {
// 			r = 0;   g = 0;   b = 255; // Bleu
// 		} else if (data->map_data.map[mapX][mapY] == 4) {
// 			r = 255; g = 255; b = 255; // Blanc
// 		} else {
// 			r = 255; g = 255; b = 0;   // Jaune (par défaut)
// 		}


//         // Assombrir la couleur si le côté est 1
//         if (side == 1) {
//             r /= 2;
//             g /= 2;
//             b /= 2;
//         }

// 		double wallX; 
//         if (side == 0) {
//             wallX = data->map_data.player_pos_y + perpWallDist * rayDirY;
//         } else {
//             wallX = data->map_data.player_pos_x + perpWallDist * rayDirX;
//         }
//         wallX -= floor(wallX);
//         int textureIndex = 0;

//         // Calculate the textureX coordinate
//         int textureWidth = data->texture[textureIndex].width;
//         int textureX = (int)(wallX * textureWidth);
//         if (side == 0 && rayDirX > 0) textureX = textureWidth - textureX - 1;
//         if (side == 1 && rayDirY < 0) textureX = textureWidth - textureX - 1;

//         verLine(x, drawStart, drawEnd, data, textureIndex, textureX);		
//         draw_ceiling(x, drawStart, data);
//         draw_floor(x, drawEnd, data);


//         x++;
//     }
// }