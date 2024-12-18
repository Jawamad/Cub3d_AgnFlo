#include "../inc/cub3d.h"

int	loop_routine(t_data *data)
{
	if (data->key_pressed == 1)
	{
		action_key(data);
		data->key_pressed = 0;
	}
	cast_rays_and_render(data);
	parse_mmap(data);
	set_player(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->img_ptr, 0, 0);
	return (1);
}

int	parsing(int ac, char **av, t_data *data)
{
	t_map_data	map_data;

	if (!routine_parsing(&map_data, ac, av))
	{
		ft_printf("Error: parsing failed\n");
		return (0);
	}
	ft_printf("parsing succeed... creating map\n");
	map_data.map_file = av[1];
	create_map_for_game(&map_data);
	display_map_data(&map_data);
	if (!too_many_player(map_data))
	{
		free_map_data(&map_data);
		ft_printf("There is less or more than one player entity on the map.\n");
		ft_printf("please verify map settings.\n");
		return (0);
	}
	data->map_data = map_data;
	return (1);
}

int	too_many_player(t_map_data map_data)
{
	int	i;
	int	j;
	int	pcount;

	i = 0;
	pcount = 0;
	if (map_data.map == NULL)
		return (0);
	while (map_data.map[i])
	{
		j = 0;
		while (map_data.map[i][j])
		{
			if (map_data.map[i][j] == '\0')
				break ;
			if (!is_player_mmap(map_data.map[i][j]))
				pcount++;
			j++;
		}
		i++;
	}
	if (pcount != 1)
		return (0);
	return (1);
}
