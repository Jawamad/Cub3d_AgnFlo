/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retreive_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agtshiba <agtshiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:28 by agtshiba          #+#    #+#             */
/*   Updated: 2025/01/09 16:03:40 by agtshiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	retreive_colors(char *treated_line, t_data *data)
{
	retrieve_colors_floor(treated_line, data);
	retrieve_colors_ceiling(treated_line, data);
}

void	retrieve_colors_floor(char *treated_line, t_data *data)
{
	int i = 0;
	int y = 0;
	int z;
	char alpha_num[4];
	int color_value;

	if (strncmp(treated_line, "F ", 2) == 0)
	{
		i += 2;
		z = 0; 
		while (z < 3)
		{
			y = 0;
			while (treated_line[i] != ',' && treated_line[i] != '\n')
			{
				alpha_num[y] = treated_line[i];
				y++;
				i++;
			}
			alpha_num[y] = '\0';
			color_value = atoi(alpha_num);
			assign_r_g_b_floor(data, z, color_value);
			if (treated_line[i] == ',')
				i++;
			z++;
		}
	}
}

void	retrieve_colors_ceiling(char *treated_line, t_data *data)
{
	int i = 0;
	int y = 0;
	int z;
	char alpha_num[4];
	int color_value;

	if (strncmp(treated_line, "C ", 2) == 0)
	{
		i += 2;
		z = 0; 
		while (z < 3)
		{
			y = 0;
			while (treated_line[i] != ',' && treated_line[i] != '\n')
			{
				alpha_num[y] = treated_line[i];
				y++;
				i++;
			}
			alpha_num[y] = '\0';
			color_value = atoi(alpha_num);
			assign_r_g_b_ceiling(data, z, color_value);
			if (treated_line[i] == ',')
				i++;
			z++;
		}
	}
}

void	assign_r_g_b_floor(t_data *data, int z, int color_value)
{
	if (z == 0)
		data->colors_floor->r = (unsigned char) color_value;
	if (z == 1)
		data->colors_floor->g = (unsigned char) color_value;
	if (z == 2)
		data->colors_floor->b = (unsigned char) color_value;
}

void	assign_r_g_b_ceiling(t_data *data, int z, int color_value)
{
	if (z == 0)
		data->colors_ceiling->r = (unsigned char) color_value;
	if (z == 1)
		data->colors_ceiling->g = (unsigned char) color_value;
	if (z == 2)
		data->colors_ceiling->b = (unsigned char) color_value;
}
