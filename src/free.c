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
}

void	free_img(t_data *data)
{
	if (data->img != NULL)
	{
		if (data->img->img_ptr != NULL)
		{
			mlx_destroy_image(data->mlx, data->img->img_ptr);
			data->img->img_ptr = NULL;
		}
	}
	free(data->colors_floor);
	free(data->colors_ceiling);
	free(data->img);
	if (data->verl_inf != NULL)
	{
		free(data->verl_inf);
		data->verl_inf = NULL;
	}
	data->img = NULL;
}

void	free_texture(t_texture *texture)
{
	if (texture->path)
		free(texture->path);
}

void	free_wall(unsigned int **wall)
{
	int	i;

	i = 0;
	while (wall[i] != NULL)
	{
		free(wall[i]);
		i++;
	}
	free(wall);
}
