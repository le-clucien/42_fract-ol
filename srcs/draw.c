// HEADER

#include "fractol.h"

int		color_set(int depth)
{
	if (depth == 0)
		return 0;
	else
		return ((depth + 6666) * 666 * 666);
}

int		iterate(t_dm *dm, t_dxy rad)
{
	if (dm->data->type == JULIA)
		return (iterate_julia(rad, dm->data->c));
	// else if (dm->data->type == MANDELBROT)
	// 	return (iterate_mandelbrot(rad, dm->data->c));
	else
		return 0;
}

void	draw_pixel(t_dm *dm, t_xy p)
{
	t_dxy	rad;

	// rad.x = (double)(position.x * 2) / dm->res->f.x - 1.0;
	// rad.y = (double)(p.y * 2) / dm->res->f.y - 1.0;
	rad.x = 1.5 * ((double)p.x - dm->res->f.x / 2) /
			(0.5 * dm->data->zoom * dm->res->f.x) + dm->data->move.x;
	rad.y = ((double)p.y - dm->res->d.y / 2) /
			(0.5 * dm->data->zoom * dm->res->d.y) + dm->data->move.y;
	dm->mlx->data[p.y * dm->res->d.x + p.x] =
			color_set(iterate(dm, rad));
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
