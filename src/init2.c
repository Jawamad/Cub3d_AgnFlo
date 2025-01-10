#include "../inc/cub3d.h"

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
		retreive_textures(data, treated_line);
		retreive_colors(treated_line, data);
		free(treated_line);
		treated_line = get_next_line(fd);
	}
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

void	retreive_textures(t_data *data, char *treated_line)
{
	int		texturepath;
	char	*path;
	int		i;

	texturepath = is_texture_path(treated_line);
	if (texturepath)
	{
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
}
