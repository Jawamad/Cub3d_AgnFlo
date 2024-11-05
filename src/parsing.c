#include "../inc/cub3d.h"

int	check_extension_file_name(char *name)
{
	int			i;
	int			y;
	const char	*needle;

	i = 0;
	y = 0;
	needle = ".cub";
	while (name[i])
	{
		if (name[i] == needle[y])
			y++;
		i++;
	}
	if (y == 4 && name[i] == '\0')
		return (1);
	return (0);
}

int	does_file_exist(char *name)
{
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("the file does not exist\n");
		return (1);
	}
	else
	{
		// ft_printf("file exist\n");
		return (0);
	}
}

int	check_walls_horizontal(t_map_data  *map_data)
{
	int	height;
	int	width;
	int	i;

	width = map_data->width;
	height = map_data->height;
	i = 0;
	while (i < width - 1)
	{
		if (map_data->map[0][i] != '1' || map_data->map[height - 1][i] != '1')
		{
			printf("\n horizontal walls : error WALL error WALL error WALL \n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls_vertical(t_map_data  *map_data)
{
	int	height;
	int	width;
	int	i;

	width = map_data->width;
	height = map_data->height;
	i = 0;
	printf("len : %d", width);
	while (i < height)
	{
		if (map_data->map[i][width - 1] != '1' || map_data->map[i][0] != '1')
		{
			printf("vertical walls : error WALL error WALL error WALL \n");
			return (0);
		}
		i++;
	}
	// printf("vertical walls : everything is okay \n");
	return (1);
}

int	check_allowed_caracters(t_map_data  *map_data)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width - 1)
		{
			if (map_data->map[y][x] != '1' && map_data->map[y][x] != '0' &&
				map_data->map[y][x] != 'N' && map_data->map[y][x] != 'S' &&
				map_data->map[y][x] != 'W' && map_data->map[y][x] != 'E')
			{
				printf("bad characters ERROR \n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

// int	count_exit_and_caracter(t_map_data  *map_data))
// {
// 	int	y;
// 	int	x;
// 	int	nb_exit;
// 	int	nb_caracter;

// 	nb_exit = 0;
// 	nb_caracter = 0;
// 	y = 0;
// 	while (y < game->map_height)
// 	{
// 		x = 0;
// 		while (x < game->map_width - 1)
// 		{
// 			if (game->map[y][x] == 'E')
// 				nb_exit += 1;
// 			else if (game->map[y][x] == 'P')
// 				nb_caracter += 1;
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (nb_exit > 1 || nb_caracter > 1)
// 		return (0);
// 	return (1);
// }