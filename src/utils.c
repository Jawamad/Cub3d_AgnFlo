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

void	coordswap(t_coord *a, t_coord *b)
{
	t_coord c;

	c = *a;
	*a = *b;
	*b = c;
}