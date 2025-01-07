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
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>


#define TILE 8
#define SC_WIDTH 1200
#define SC_HEIGHT 600
#define SPEED 0.05
#define ROT_SPEED 0.02
#define GAME_NAME "Cub3d"
#define FOV 66
/* Structure */

typedef struct s_texture
{
	void	*img;
	// char	*addr;
	unsigned int *addr;  // 1D array of pixels
	int		bits_per_pixels;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	char	*path;
}	t_texture;

typedef struct s_coord{
	int	x;
	int	y;
}	t_coord;

typedef struct s_pos{
	float	x;
	float	y;
}	t_pos;

typedef struct s_dpos{
	double	x;
	double	y;
}	t_dpos;

typedef struct s_player{
	t_pos	ppos;
	float	angle;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	t_player;

typedef struct s_arrow{
	t_coord	head;
	t_coord	left;
	t_coord	right;
}	t_arrow;

typedef struct s_map_data{
	char			**map;
	int				width;
	int				height;
	t_player		player;
	double			player_pos_x;
	double			player_pos_y;
	int				check_pos_x;
	int				check_pos_y;
	int				map_error;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*map_file;
}	t_map_data;

typedef struct s_img{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data{
	int				screenWidth;
	int				screenHeight;
	void			*mlx;
	void			*mlx_win;
	t_img			*img;
	t_texture		texture[4];
	t_dpos			raydir;
	unsigned int	**wall;
	char			keys[256];
	int				mouse_x;
	t_map_data		map_data;
}	t_data;

// typedef struct {
// 	int	r;
// 	int	g;
// 	int	b;
// } ColorRGB;


/* Fonctions */

int key_release(int keycode, t_data *data);
int key_press(int keycode, t_data *data);
int parsing(int ac, char **av, t_data *data);
int too_many_player(t_map_data map_data);

/* input.c */
void	action_key(t_data *data);
int		handle_keypress(int keycode, t_data *data);
int		handle_mouse_move(int x, int y, t_data *data);
int		close_and_clean(t_data *data);

/* camera.c */
void	turn_left(t_map_data *map_data);
void	turn_right(t_map_data *map_data);

/* movement.c */
void	strafe_left(t_map_data *map_data);
void	strafe_right(t_map_data *map_data);
void	forward(t_map_data *map_data);
void	backward(t_map_data *map_data);
int	valid_pos(t_map_data *map_data, int x, int y);

/* minimap/map_pos.c */
t_pos	create_pos(float x, float y);
t_coord	create_coord(int x, int y);

/* img_gen/img.c*/
void	put_pixel(t_img *img, int x, int y, int color);
void	init_img(t_data *data);

/* utils.c */
void	free_map_data(t_map_data *map_data);
void	free_array(char **array);
void	coordswap(t_coord *a, t_coord *b);
void	clean_all(t_data *data);
void	free_wall(unsigned int **wall);
void	free_texture(t_texture *texture, void *mlx);
void	free_img(t_data *data);

/* minimap/create_mmap.c */
int		loop_routine(t_data *data);
void	parse_mmap(t_data *data);
void	draw_tile(t_data *data, char c, t_coord *pen);
int		select_color(char c);
int		is_onmap(char c);

/* minimap/player.c */
void	set_player(t_data *data);
void	set_arrow_point(t_player* player, t_arrow *arrow);
int		is_player_mmap(char c);

/* mlxinit.c */
void	init_map(t_data *data);
void	init_win(t_data *data);
void	calc_plane(t_player *player);

/* raycast/draw.c */
int		interpolate_x(t_coord p1, t_coord p2, int y);
void	fill_triangle(t_data *data, t_arrow *player);
void	draw_line(t_data *data, t_coord a, t_coord b);
void	calc_line(t_coord *d, t_coord *s, t_coord *a, int *err);
void	fill_part(t_coord *start, t_coord *end, t_arrow *player, int y);

/*init.c*/
int		if_temp_null(t_map_data  *map_data, char **temp);
char	**manage_temp(t_map_data  *map_data, char *line);
int		save_line_in_map(t_map_data  *map_data, char *line);
int		create_map(t_map_data  *map_data);
void	treat_line(char *treated_line, t_map_data *map_data);
int		create_map_for_game(t_map_data  *map_data);
int		define_player_pos(t_map_data  *map_data);
int		define_check_pos(t_map_data  *map_data);

/*src/parsing.c*/
int	check_extension_file_name(char *name);
int	does_file_exist(char *name);
void display_map_data(t_map_data  *map_data);
int	check_walls_horizontal(t_map_data  *map_data);
int	check_walls_vertical(t_map_data  *map_data);
int	check_allowed_caracters(t_map_data  *map_data);


/*src/floodfill.c*/
void	flood_map(t_map_data  *map_data, int x, int y);
int		check_flood_fill(t_map_data  *map_data);
int		map_free_after_flood_fill(t_map_data *map_data);
int		routine_floodfill(t_map_data *map_data);
int		routine_parsing(t_map_data *map_data, int ac, char **av);

/* routine.c */
int		loop_routine(t_data *data);

/* raycasting */
void	draw_ceiling(int x, int drawStart, t_data *data);
void	draw_floor(int x, int drawEnd, t_data *data);
void verLine(int x, int drawStart, int drawEnd, t_data *data, int textureIndex, int textureX);
void	cast_rays_and_render(t_data *data);
void	rotate(t_player *data, double rotSpeed, int direction);

/* init texture */
void init_images_walls(t_data *data);
// void init_walls(t_data *data, int i);
// void allocate_wall(t_data *data);
void allocate_wall(t_data *data, int i);
void printAllPixels(t_data *data, int i);
void init_texture(t_data *data);
// void init_texture(t_data *data);

/* init2.c*/
int	retreive_infos_textures(t_data *data, t_map_data *map_data, char **av);
// int	retreive_infos_textures(t_data *data, char **av);

// int	retreive_infos_textures(t_map_data *map_data, char **av);
// void retreive_textures(char *treat_line);
void retreive_colors(char *treated_line);

void retreive_textures(t_data *data, char *treated_line);



void	calc_deltadist(t_data *data, t_dpos *deltadist);
void	calc_sidedist(t_data *data, t_dpos *sidedist, t_coord *map, t_dpos deltadist);
void	init_step(t_data *data,t_coord *step);
void	init_perp_wall_d(int side, double *perp_wall_d, t_dpos sidedist, t_dpos deltadist);
// void	init_perp_wall_d(int *side, double *perp_wall_d, t_dpos sidedist, t_dpos deltadist);
void	calc_dist(t_data *data, t_coord *map, int *side, double *perp_wall_d);
// void	draw_define(int	perp_wall_d, int *drawstart, int *drawend);
void	draw_define(double perp_wall_d, int *drawstart, int *drawend);
void	calc_wallx(double *wallx, t_data *data, int side, double perp_wall_d);
int	get_textureindex(t_data *data, int side);
// int	get_texturex(t_data *data, double wallx, int side, double distance_to_wall);
int	raycast(t_data *data, int *drawstart, int *drawend, int *texturex);
void	init_raydir(t_data *data, int x);
int	get_texturex(t_data *data, double wallx, int side);
// int	get_texturex(t_data *data, double wallx, int side, double perp_wall_d);
#endif