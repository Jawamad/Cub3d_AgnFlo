#include "../inc/cub3d.h"

void	init_win(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, SC_WIDTH, SC_HEIGHT, GAME_NAME);
}
/* data->map_data.player_pos_y correspond  data->map_data.player.ppos.x qui correspond a l abscisse
 data->map_data.player_pos_x correspond  data->map_data.player.ppos.y qui correspond a l ordonee
 */
void	init_map(t_data *data)
{
	char	c;

	data->screenWidth = SC_WIDTH;
    data->screenHeight = SC_HEIGHT;
	define_player_pos(&data->map_data);
	data->map_data.player.angle = M_PI;
	data->key_pressed = 0;
	data->keycode = 0;
	data->mouse_x = SC_WIDTH / 2;
	data->map_data.player.ppos.x = data->map_data.player_pos_y;
	data->map_data.player.ppos.y = data->map_data.player_pos_x;
	c = data->map_data.map[(int)data->map_data.player.ppos.y][(int)data->map_data.player.ppos.x];
	if (c == 'N')
		data->map_data.player.angle = 3 * data->map_data.player.angle / 2;
	else if (c == 'S')
		data->map_data.player.angle /= 2;
	else if (c == 'E')
		data->map_data.player.angle = 0;
	data->map_data.player.dirX = -1;
	data->map_data.player.dirY = 0;
	/* data->map_data.player.dirX = cos(data->map_data.player.angle);
	data->map_data.player.dirY = sin(data->map_data.player.angle); */
	data->map_data.player.planeX = 0;
	data->map_data.player.planeY = 0.66;
}
