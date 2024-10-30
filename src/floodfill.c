#include "../inc/cub3d.h"

// int	map_free_after_flood_fill(t_game *game)
// {
// 	int		nbr_of_lines;

// 	nbr_of_lines = 0;
// 	if (game->map != NULL)
// 	{
// 		while (nbr_of_lines < game->map_height)
// 		{
// 			free(game->map[nbr_of_lines]);
// 			game->map[nbr_of_lines] = NULL;
// 			nbr_of_lines++;
// 		}
// 		free(game->map);
// 	}
// 	return (1);
// }

// void	flood_map(t_game *game, int x, int y)
// {
// 	if (game->map[y][x] == 'P' || game->map[y][x] == '1'
// 		|| game->map[y][x] == 'F')
// 		return ;
// 	game->map[y][x] = 'F';
// 	flood_map(game, x, y + 1);
// 	flood_map(game, x, y - 1);
// 	flood_map(game, x + 1, y);
// 	flood_map(game, x - 1, y);
// }

// int	check_flood_fill(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	flood_map(game, game->player_pos_x, game->player_pos_y);
// 	while (i < game->map_height)
// 	{
// 		while (j < game->map_width)
// 		{
// 			if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
// 			{
// 				return (0);
// 			}
// 			j++;
// 		}
// 		i++;
// 		j = 0;
// 	}
// 	return (1);
// }

// int	check_flood_fill_map(t_game *game, t_gamefile *gamefile)
// {
// 	if (!create_map(game, gamefile))
// 	{
// 		ft_printf("Error: Failed to create map\n");
// 		return (0);
// 	}
// 	if (!map_len(game))
// 		return (0);
// 	if (!check_map(game))
// 		return (0);
// 	if (!display_player_pos(game))
// 		return (0);
// 	flood_map(game, game->player_pos_x, game->player_pos_y);
// 	if (!check_flood_fill(game))
// 	{
// 		ft_printf("Error: Failed flood map\n");
// 		return (0);
// 	}
// 	if (!map_free_after_flood_fill(game))
// 	{
// 		ft_printf("Error: Failed to free map after flood fill\n");
// 		return (0);
// 	}
// 	return (1);
// }