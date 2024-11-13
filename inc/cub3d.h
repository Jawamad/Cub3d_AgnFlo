#ifndef CUB3D_H
# define CUB3D_H

/* Library */

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <math.h>


//#define M_PI       3.14159265358979323846;
#define TILE 16
#define SC_WIDTH 1200
#define SC_HEIGHT 600
#define SPEED 0.1
#define GAME_NAME "Cub3d"
/* Structure */

typedef struct s_coord{
	int	x;
	int	y;
}	t_coord;

typedef struct s_pos{
	float	x;
	float	y;
}	t_pos;

typedef struct s_player{
	t_pos	ppos;
	float	angle;
}	t_player;

typedef struct s_arrow{
	t_coord	head;
	t_coord	left;
	t_coord	right;
}	t_arrow;

typedef struct s_map_data{
	char			**map;
	int				p_count;
	int				width;
	int				height;
	t_player		player;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*cc;
	char			*cf;
	int				count_line;
}	t_map_data;

typedef struct s_img{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data{
	int			keycode;
	int			key_pressed;
	int			mouse_x;
	void		*mlx;
	void		*mlx_win;
	t_img		*img;
	t_map_data	map_data;
}	t_data;


/* Fonctions */

/* input.c */
void	action_key(t_data *data);
int		handle_keypress(int keycode, t_data *data);
int		handle_mouse_move(int x, int y, t_data *data);

/* camera.c */
void	turn_left(t_map_data *map_data);
void	turn_right(t_map_data *map_data);

/* movement.c */
void	strafe_left(t_map_data *map_data);
void	strafe_right(t_map_data *map_data);
void	forward(t_map_data *map_data);
void	backward(t_map_data *map_data);
int		valid_pos(t_map_data *map_data, t_pos player_pos);

/* minimap/map_pos.c */
t_pos	create_pos(float x, float y);
t_coord	create_coord(int x, int y);

/* img_gen/img.c*/
void	put_pixel(t_img *img, int x, int y, int color);
void	init_img(t_data *data);

/* utils.c */
void	free_array(char **array);
void	coordswap(t_coord *a, t_coord *b);
void	clean_all(t_data *data);

/* minimap/create_mmap.c */
int		loop_routine(t_data *data);
void	parse_mmap(t_data *data);
void	draw_tile(t_data *data, char c, t_coord *pen);
int		select_color(char c);
int		is_onmap(char c);

/* minimap/player.c */
t_pos	search_player(t_data *data);
void	set_player(t_data *data);
void	set_arrow_point(t_player* player, t_arrow *arrow);
int		is_player_mmap(char c);

/* mlxinit.c */
void	init_map(t_data *data);
void	init_win(t_data *data);

/* raycast/draw.c */
int		interpolate_x(t_coord p1, t_coord p2, int y);
void	fill_triangle(t_data *data, t_coord p1, t_coord p2, t_coord p3);
void	draw_line(t_data *data, t_coord a, t_coord b);
void	calc_line(t_coord *d, t_coord *s, t_coord *a, int *err);

/* routine.c */
int		loop_routine(t_data *data);

#endif