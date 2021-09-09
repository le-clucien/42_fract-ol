/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:28:50 by clucien           #+#    #+#             */
/*   Updated: 2021/07/12 17:28:53 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_set(int depth, int color_shift)
{
	if (depth == 0 || depth == MAX_ITERATION)
		return (0);
	return (depth * (2 + color_shift * 2)
		| depth * (3 + color_shift / 2) << 8
		| depth * (3 + color_shift) << 16);
}

int	iterate(t_dm *dm, t_dxy rad)
{
	if (dm->data->type == JULIA)
		return (iterate_julia(rad, dm->data->c));
	else if (dm->data->type == MANDELBROT)
		return (iterate_mandelbrot(rad));
	else if (dm->data->type == TRICORN)
		return (iterate_tricorn(rad));
	else
		return (0);
}

void	draw_pixel(t_dm *dm, t_xy p)
{
	t_dxy	rad;

	rad.x = 1.5 * ((double)p.x - dm->res->f.x / 2)
		/ (0.5 * dm->data->zoom * dm->res->f.x) + dm->data->move.x;
	rad.y = ((double)p.y - dm->res->d.y / 2)
		/ (0.5 * dm->data->zoom * dm->res->d.y) + dm->data->move.y;
	dm->mlx->data[p.y * dm->res->d.x + p.x]
		= color_set(iterate(dm, rad), dm->data->color_shift);
}

void	draw_fractal(t_dm *dm)
{
	t_xy	position;

	position.x = 0;
	while (position.x < dm->res->d.x)
	{
		position.y = 0;
		while (position.y < dm->res->d.y)
		{
			draw_pixel(dm, position);
			position.y++;
		}
		position.x++;
	}
	mlx_put_image_to_window(dm->mlx->ptr, dm->mlx->win, dm->mlx->img, 0, 0);
}
