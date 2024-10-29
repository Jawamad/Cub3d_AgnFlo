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
#define TILE 16;

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

typedef struct s_data{
	void			*mlx;
	void			*mlx_win;
	t_map_data		map_data;
}	t_data;

/* Fonctions */

/* minimap/map_pos.c */
t_pos	create_pos(float x, float y);
t_coord	create_coord(int x, int y);
/* utils/ft_error.c */


/* utils.c */
void	free_array(char **array);


/* minimap/map_checking.c */
int	parse_map(t_data *data);
void	draw_tile(t_data *data, char c, t_coord *pen);
int	select_color(char c);
int is_onmap(char c);

/* raycast/pos.c */

/* mlxinit.c */
void  init_map(t_data *data);
void init_win(t_data *data);

/* raycast/draw.c */


#endif