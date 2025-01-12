#include "../inc/cub3d.h"

void	allocate_colors(t_data *data)
{
	data->colors_floor = malloc(sizeof(t_color));
	data->colors_ceiling = malloc(sizeof(t_color));
}

int	retreive_infos_textures(t_data *data, char **av)
{
	int		fd;
	char	*treated_line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("error: cannot read file");
		return (0);
	}
	treated_line = get_next_line(fd);
	if (!treated_line)
		return (close(fd), 0);
	while (treated_line)
	{
		if (!retreive_textures(data, treated_line))
			return (0);
		retreive_colors(treated_line, data);
		free(treated_line);
		treated_line = get_next_line(fd);
	}
	if (!check_texture_file_exists(data))
		return (0);
	close(fd);
	return (1);
}

int	is_texture_path(char *treated_line)
{
	if (strncmp(treated_line, "NO ", 3) == 0)
		return (1);
	if (strncmp(treated_line, "SO ", 3) == 0)
		return (2);
	if (strncmp(treated_line, "WE ", 3) == 0)
		return (3);
	if (strncmp(treated_line, "EA ", 3) == 0)
		return (4);
	return (0);
}

int	retreive_textures(t_data *data, char *treated_line)
{
	int		texturepath;
	char	*path;
	int		i;

	texturepath = is_texture_path(treated_line);
	if (texturepath)
	{
		if (!check_extension_file_name(treated_line, 2))
		{
			ft_printf("Error: invalid texture extension\n");
			return (0);
		}
		path = ft_strchr(treated_line, ' ');
		while (*path == ' ')
			path++;
		if (path)
		{
			i = 0;
			while (path[i] != '\n')
				i++;
			path[i] = '\0';
			data->texture[texturepath - 1].path = ft_strdup(path);
		}
	}
	return (1);
}

int check_texture_file_exists(t_data *data)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (access(data->texture[i].path, F_OK) == 0) {
			i++;
		} else {
			printf("Error : the texture path does not exist\n");
			return (0);
		}
	}
	return (1);
}