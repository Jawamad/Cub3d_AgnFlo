#include "../inc/cub3d.h"

int	retreive_infos_textures(t_data *data, t_map_data *map_data, char **av)
{
	int		fd;
	char	*treated_line;

	data->map_data.map_file = av[1];
	fd = open(data->map_data.map_file, O_RDONLY);	

	if (fd < 0)
	{
		printf("error: cannot read file");
		return (0);
	}
	(void)map_data;
	treated_line = get_next_line(fd);
	if (!treated_line)
		return (close(fd), 0);
	// int i;

	// i = 0;
	while (treated_line)
	{
		retreive_textures(data, treated_line);
		free(treated_line);
		treated_line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void retreive_textures(t_data *data, char *treated_line)
{
	// int i;

	// i = 0;
	// while (i < 4)
	// {
	// 	data->texture[i].path = malloc(100 * sizeof(char));
	// 	i++;
	// }

	if (strncmp(treated_line, "NO ", 3) == 0)
    {
        char *path;
		
		path = ft_strchr(treated_line, ' ');
		while (*path == ' ')
			path++;
        if (path)
        {
			int i = 0;
			while (path[i] != '\n')
				i++;
			path[i] = '\0';
            printf("TL texture part NO: %s\n", path);
			data->texture[0].path = ft_strdup(path);
        }
    }
	if (strncmp(treated_line, "SO ", 3) == 0)
    {
        char *path;
		
		path = ft_strchr(treated_line, ' ');
		while (*path == ' ')
			path++;
        if (path)
        {
			int i = 0;
			while (path[i] != '\n')
				i++;
			path[i] = '\0';
            printf("TL texture part SO: %s\n", path);
			data->texture[1].path = ft_strdup(path);
        }
    }
	if (strncmp(treated_line, "WE ", 3) == 0)
    {
        char *path;
		
		path = ft_strchr(treated_line, ' ');
		while (*path == ' ')
			path++;
        if (path)
        {
			int i = 0;
			while (path[i] != '\n')
				i++;
			path[i] = '\0';
            printf("TL texture part WE: %s\n", path);
			data->texture[2].path = ft_strdup(path);
        }
    }
	if (strncmp(treated_line, "EA ", 3) == 0)
    {
        char *path;
		
		path = ft_strchr(treated_line, ' ');
		while (*path == ' ')
			path++;
        if (path)
        {
			int i = 0;
			while (path[i] != '\n')
				i++;
			path[i] = '\0';
            printf("TL texture part EA: %s\n", path);
			data->texture[3].path = ft_strdup(path);
        }
    }
}

void retreive_colors(char *treated_line)
{
	if (strncmp(treated_line, "C ", 2) == 0)
		printf("%s", treated_line);
	else if (strncmp(treated_line, "F ", 2) == 0)
		printf("%s", treated_line);
}