#include "../inc/cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_map_data(t_map_data *map_data)
{
	if (map_data->map[0] != NULL)
		free_array(map_data->map);
	if (map_data->no != NULL)
		free(map_data->no);
	if (map_data->so != NULL)
		free(map_data->so);
	if (map_data->we != NULL)
		free(map_data->we);
	if (map_data->ea != NULL)
		free(map_data->ea);
	if (map_data->map_file != NULL)
		free(map_data->map_file);
}
void	clean_all(t_data *data)
{
	if (data->map_data.map[0] != NULL)
		free_array(data->map_data.map);
	if (data->map_data.no != NULL)
		free(data->map_data.no);
	if (data->map_data.so != NULL)
		free(data->map_data.so);
	if (data->map_data.we != NULL)
		free(data->map_data.we);
	if (data->map_data.ea != NULL)
		free(data->map_data.ea);
	//free(data->img->img_ptr);
	//free(data->img->addr);
	//free(data->img);
	//free(data->mlx_win);
	free(data->mlx);
	free(data);
}

void	coordswap(t_coord *a, t_coord *b)
{
	t_coord	c;

	c = *a;
	*a = *b;
	*b = c;
}
