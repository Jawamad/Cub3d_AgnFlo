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
		ft_printf("the file does not exist");
		return (0);
	}
	else
		return (1);
}

// int	check_walls_horizontal(t_game *game)
// {
// 	int	height;
// 	int	len;
// 	int	i;

// 	len = game->map_width;
// 	height = game->map_height;
// 	i = 0;
// 	while (i < len - 1)
// 	{
// 		if (game->map[0][i] != '1' || game->map[height - 1][i] != '1')
// 		{
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	check_walls_vertical(t_game *game)
// {
// 	int	height;
// 	int	len;
// 	int	i;

// 	len = game->map_width - 1;
// 	height = game->map_height;
// 	i = 0;
// 	while (i < height)
// 	{
// 		if (game->map[i][len - 1] != '1' || game->map[i][0] != '1')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	check_allowed_caracters(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < game->map_height)
// 	{
// 		x = 0;
// 		while (x < game->map_width - 1)
// 		{
// 			if (game->map[y][x] != '1' && game->map[y][x] != '0' &&
// 				game->map[y][x] != 'N' && game->map[y][x] != 'S' &&
// 					game->map[y][x] != 'E')
// 				return (0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (1);
// }

// int	count_exit_and_caracter(t_game *game)
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