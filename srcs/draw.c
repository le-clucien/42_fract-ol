// HEADER

#include "fractol.h"

void	draw_pixel(t_dm *dm, t_xy position)
{
	float	radx;
	float	rady;

	radx = ((float)(position.x * 2) / (float)dm->res->x) - 1;
	rady = ((float)(position.y * 2) / (float)dm->res->y) - 1;
	dm->mlx->data[position.y * dm->res->x + position.x] = roundf(radx * 1000) / roundf(rady * 1000);
}

void	draw_fractal(t_dm *dm)
{
	t_xy	position;

	position.x = 0;
	while (position.x <= dm->res->x)
	{
		position.y = 0;
		while (position.y <= dm->res->y)
		{
			draw_pixel(dm, position);
			position.y++;
		}
		position.x++;
	}
}
