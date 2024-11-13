#include "../../inc/cub3d.h"

t_pos	create_pos(float x, float y)
{
	t_pos	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_coord	create_coord(int x, int y)
{
	t_coord	point;

	point.x = x;
	point.y = y;
	return (point);
}
