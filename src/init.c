#include "../inc/cub3d.h"

// allocating temp to size of map plus NULL
// while map, pass everything in temp
// pass new line in temp
// if temp NULL, free temp
// if strdup fails, free the already allocated memory
// free game
// pass content of temp in game->map
int	if_temp_null(t_map_data  *map_data, char **temp)
{
	int		y;

	if (!temp)
	{
		y = 0;
		while (y < map_data->height)
		{
			free(temp[y]);
			y++;
		}
		free(temp);
		return (0);
	}
	return (1);
}

char	**manage_temp(t_map_data  *map_data, char *line)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * (map_data->height + 1));
	if (!temp)
		return (0);
	temp[map_data->height - 1] = NULL;
	while (i < map_data->height - 1)
	{
		temp[i] = map_data->map[i];
		i++;
	}
	temp[i] = ft_strdup(line);
	if (!temp[i])
	{
		if_temp_null(map_data, temp);
		return (NULL);
	}
	return (temp);
}

int	save_line_in_map(t_map_data  *map_data, char *line)
{
	char	**temp;

	if (!line)
		return (0);
	map_data->height++;
	temp = manage_temp(map_data, line);
	if (map_data->map)
		free(map_data->map);
	map_data->map = temp;
	return (1);
}
int	create_map(t_map_data  *map_data)
{
	int		fd;
	int		i;	
	char	*treated_line;

	i = 0;
	fd = open(map_data->map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	ft_memset(map_data, 0, sizeof(t_map_data));
	treated_line = get_next_line(fd);
	if (!treated_line)
	{
		close(fd);
		return (0);
	}
	while (treated_line)
	{
		save_line_in_map(map_data, treated_line);
		free(treated_line);
		treated_line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

int	create_map_for_game(t_map_data  *map_data)
{
	if (!create_map(map_data))
	{
		ft_printf("Error: Failed to create map\n");
		fflush(stdout);
		return (0);
	}
	// map_len(game);
	// if (!check_walls(game))
	// 	return (0);
	// if (!check_map(game))
	// 	return (0);
	return (1);
}