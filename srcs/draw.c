// HEADER

#include "fractol.h"

int		color_set(int depth)
{
	return ((depth + 6666) * 666 * 666);
}

void	draw_pixel(t_dm *dm, t_xy position)
{
	t_dxy	rad;
	int		iterations;

	rad.x = (double)(position.x * 2) / dm->res->f.x - 1.0;
	rad.y = (double)(position.y * 2) / dm->res->f.y - 1.0;
	if (dm->data->type == JULIA)
		iterations = iterate_julia(rad, dm->data->c);
	if (iterations)
		iterations = color_set(iterations);
	else
		iterations = 0;
	dm->mlx->data[position.y * dm->res->d.x + position.x] = iterations;
}

void	draw_fractal(t_dm *dm)
{
	t_xy	position;

	position.x = 0;
	while (position.x <= dm->res->d.x)
	{
		position.y = 0;
		while (position.y <= dm->res->d.y)
		{
			draw_pixel(dm, position);
			position.y++;
		}
		position.x++;
	}
	mlx_put_image_to_window(dm->mlx->ptr, dm->mlx->win, dm->mlx->img, 0, 0);
}
