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
/* Structure */


//#define M_PI       3.14159265358979323846;
#define TILE 16
#define SC_WIDTH 1200
#define SC_HEIGHT 600
#define GAME_NAME "Cub3d"

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
	t_pos head;
	t_pos left;
	t_pos right;
}	t_arrow;

typedef struct s_map_data{
	char			**map;
	int	nb_column;
	int	nb_row;
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
	void		*mlx;
	void		*mlx_win;
	t_img		*img;
	t_map_data	map_data;
}	t_data;


/* Fonctions */

/* minimap/map_pos.c */
t_pos	create_pos(float x, float y);
t_coord	create_coord(int x, int y);
/* img_gen/img.c*/
void	init_img(t_data *data);

/* utils.c */
void	free_array(char **array);
void	put_pixel(t_img *img, int x, int y, int color);

/* minimap/map_checking.c */
void	parse_map(t_data *data);
void	draw_tile(t_data *data, char c, t_coord *pen);
int	select_color(char c);
int is_onmap(char c);

/* raycast/pos.c */

/* mlxinit.c */
void  init_map(t_data *data);
void init_win(t_data *data);

/* raycast/draw.c */


#endif