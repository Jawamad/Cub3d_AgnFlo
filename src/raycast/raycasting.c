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
        printf("sideDist %f\n",sideDistX);
        // DDA
        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            if (data->map_data.map[mapX][mapY] > 0) {
                hit = 1;
            }
        }
        // Calculer la distance du mur
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

        draw_ceiling(x, drawStart, data);
        printf("drawEnd %d\n", drawEnd);
        draw_floor(x, drawEnd, data);
        verLine(x, drawStart, drawEnd, r, g, b, data);

        x++;
    }
    //mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img_ptr, 0, 0);
}
/* void cast_rays_and_render(t_data *data)
{
    int w = data->screenWidth;
    int h = data->screenHeight;
    int x = 0;

    while (x < w) 
    {
        double cameraX = 2 * x / (double)w - 1;
        double rayDirX = data->map_data.player.dirX + (data->map_data.player.planeX) * cameraX;
        double rayDirY = data->map_data.player.dirY + (data->map_data.player.planeY) * cameraX;

        // Convertir la position du joueur en indices de la carte
        int mapY = (int)(data->map_data.player.ppos.y); // Correspond à map[y]
        int mapX = (int)(data->map_data.player.ppos.x); // Correspond à map[x]

        double sideDistX;
        double sideDistY;
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

        double perpWallDist;
        int stepX;
        int stepY;
        int hit = 0;
        int side;

        // Calculer le pas et la distance initiale pour le DDA
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = ((data->map_data.player.ppos.x) - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - (data->map_data.player.ppos.x)) * deltaDistX;
        }

        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = ((data->map_data.player.ppos.y) - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - (data->map_data.player.ppos.y)) * deltaDistY;
        }

        // DDA
        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            // Vérifier si le rayon a touché un mur
            if (data->map_data.map[mapY][mapX] > 0) {
                hit = 1;
            }
        }

        // Calculer la distance perpendiculaire au mur
        if (side == 0) {
            perpWallDist = (sideDistX - deltaDistX);
        } else {
            perpWallDist = (sideDistY - deltaDistY);
        }

        // Calculer la hauteur de la ligne
        int lineHeight = (int)(h / perpWallDist);
        int drawStart = -lineHeight / 2 + h / 2;
        if (drawStart < 0) {
            drawStart = 0;
        }
        int drawEnd = lineHeight / 2 + h / 2;
        if (drawEnd >= h) {
            drawEnd = h - 1;
        }

        // Déterminer la couleur en fonction de la carte
        unsigned char r, g, b;

        if (data->map_data.map[mapY][mapX] == 1) {
            r = 255; g = 0; b = 0;   // Rouge
        } else if (data->map_data.map[mapY][mapX] == 2) {
            r = 0;   g = 255; b = 0;   // Vert
        } else if (data->map_data.map[mapY][mapX] == 3) {
            r = 0;   g = 0;   b = 255; // Bleu
        } else if (data->map_data.map[mapY][mapX] == 4) {
            r = 255; g = 255; b = 255; // Blanc
        } else {
            r = 255; g = 255; b = 0;   // Jaune (par défaut)
        }

        // Assombrir la couleur si le côté est 1 (mur vertical)
        if (side == 1) {
            r /= 2;
            g /= 2;
            b /= 2;
        }

        // Dessiner les éléments
        draw_ceiling(x, drawStart, data);
        draw_floor(x, drawEnd, data);
        verLine(x, drawStart, drawEnd, r, g, b, data);

        x++;
    }
} */



// #include "../cub3d.h"

// void cast_rays_and_render(t_data *data)
// {
// 	unsigned char RGB_Red[] = {255, 0, 0};
//     unsigned char RGB_Green[] = {0, 255, 0};
//     unsigned char RGB_Blue[] = {0, 0, 255};
//     unsigned char RGB_White[] = {255, 255, 255};
//     unsigned char RGB_Yellow[] = {255, 255, 0};


//     int w = data->screenWidth;
//     int h = data->screenHeight;

//     int x = 0;
//     while (x < w) 
// 	{
//         double cameraX = 2 * x / (double)w - 1;  // Correcting the calculation for cameraX
//         double rayDirX = data->dirX + (data->planeX) * cameraX; // Dereference planeX
//         double rayDirY = data->dirY + (data->planeY) * cameraX; // Dereference planeY
//         int mapX = (int)(data->posX); // Dereference posX and cast to int
//         int mapY = (int)(data->posY); // Dereference posY and cast to int
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

//         if (rayDirX < 0) {
//             stepX = -1;
//             sideDistX = ((data->posX) - mapX) * deltaDistX; // Dereference posX
//         } else {
//             stepX = 1;
//             sideDistX = (mapX + 1.0 - (data->posX)) * deltaDistX; // Dereference posX
//         }

//         if (rayDirY < 0) {
//             stepY = -1;
//             sideDistY = ((data->posY) - mapY) * deltaDistY; // Dereference posY
//         } else {
//             stepY = 1;
//             sideDistY = (mapY + 1.0 - (data->posY)) * deltaDistY; // Dereference posY
//         }

//         // Perform DDA
//         while (hit == 0) {
//             if (sideDistX < sideDistY) {
//                 sideDistX += deltaDistX;
//                 mapX += stepX;
//                 side = 0;
//             } else {
//                 sideDistY += deltaDistY;
//                 mapY += stepY;
//                 side = 1;
//             }

//             if (data->worldMap[mapX][mapY] > 0) {
//                 hit = 1;
//             }
//         }

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


// 		unsigned char *color;
// 		switch (data->worldMap[mapX][mapY]) {
// 			case 1: color = RGB_Red; break;
// 			case 2: color = RGB_Green; break;
// 			case 3: color = RGB_Blue; break;
// 			case 4: color = RGB_White; break;
// 			default: color = RGB_Yellow; break;
// 		}

//         if (side == 1) {
//             color[0] /= 2;
//             color[1] /= 2;
//             color[2] /= 2;
//         }
// 		verLine(x, drawStart, drawEnd, data);
    

//         x++;
//     }
// }
