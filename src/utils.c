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

void	free_img(t_data *data)
{
	if (data->img != NULL)
	{
		if(data->img->img_ptr != NULL)
		{
			mlx_destroy_image(data->mlx, data->img->img_ptr);
			data->img->img_ptr = NULL;
		}
	}
	free(data->img);
	data->img = NULL;
}
void free_texture(t_texture *texture, void *mlx)
{
	if (texture->img)
		mlx_destroy_image(mlx, texture->img);
	if (texture->addr)
		free(texture->addr);
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

void	clean_all(t_data *data)
{
	/* int	i;

	i = 0;
	while (i < 4)
	{
		free_texture(&data->texture[i], data->mlx);
		i++;
	} */
	free_img(data);
	free_map_data(&data->map_data);
	free_wall(data->wall);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	if(data->mlx)
		free(data->mlx);
}

void	coordswap(t_coord *a, t_coord *b)
{
	t_coord	c;

	c = *a;
	*a = *b;
	*b = c;
}
