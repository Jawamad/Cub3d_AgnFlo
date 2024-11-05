#include "../../inc/cub3d.h"

void draw_line(t_data *data, t_coord a, t_coord b)
{
	t_coord	d;
	t_coord	s;
	int		err;


	d.x = abs(b.x - a.x);
	d.y = abs(b.y - a.y);
	s.x = -1;
	if (a.x < b.x)
		s.x = 1;
	s.y = -1;
	if (a.y < b.y)
		s.y = 1;
	err = d.x - d.y;
	while(1)
	{
		put_pixel(data->img, a.x, a.y , 0x0000FF);
		if (a.x == b.x  && a.y == b.y)
			break;
		calc_line(&d, &s, &a, &err);
	}
}

void calc_line(t_coord *d, t_coord *s, t_coord *a, int *err)
{
	int		e2;

	e2 = 2 * (*err);
	if (e2 > -d->y)
	{
		*err -= d->y;
		a->x += s->x;
	}
	if (e2 < d->x)
	{
		*err += d->x;
		a->y += s->y;
	}
}

int interpolate_x(t_coord p1, t_coord p2, int y)
{
	if (p1.y == p2.y)
		return (p1.x);
	return(p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y));
}

void fill_triangle(t_data *data, t_coord p1, t_coord p2, t_coord p3)
{
	int		y;
	t_coord	start;
	t_coord	end;

	if (p1.y > p2.y)
		coordswap(&p1, &p2);
	if (p1.y > p3.y)
		coordswap(&p1, &p3);
	if (p2.y > p3.y)
		coordswap(&p2, &p3);
	y = p1.y;
	while(y <= p2.y)
	{
		start.x = interpolate_x(p1, p3, y);
		start.y = y;
		end.x =interpolate_x(p1, p2, y);
		end.y = y;
		draw_line(data, start, end);
		y++;
	}
	y = p2.y;
	while(y <= p3.y)
	{
		start.x = interpolate_x(p1, p3, y);
		start.y = y;
		end.x =interpolate_x(p2, p3, y);
		end.y = y;
		draw_line(data, start, end);
		y++;
	}
}
