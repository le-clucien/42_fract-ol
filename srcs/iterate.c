/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:29:38 by clucien           #+#    #+#             */
/*   Updated: 2021/07/12 17:29:41 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_julia(t_dxy z, t_dxy c)
{
	int		iterations;
	t_dxy	tmp;

	iterations = 0;
	while (sqrt(z.x * z.x + z.y * z.y) <= 2.0 && iterations < MAX_ITERATION)
	{
		tmp.x = z.x;
		tmp.y = z.y;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = 2 * tmp.x * tmp.y + c.y;
		iterations++;
	}
	return (iterations);
}

int	iterate_mandelbrot(t_dxy z)
{
	int		iterations;
	t_dxy	tmp;
	t_dxy	p;

	p = z;
	z.x = 0;
	z.y = 0;
	iterations = 0;
	while (sqrt(z.x * z.x + z.y * z.y) <= 2.0 && iterations < MAX_ITERATION)
	{
		tmp.x = z.x;
		tmp.y = z.y;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + p.x;
		z.y = 2 * tmp.x * tmp.y + p.y;
		iterations++;
	}
	return (iterations);
}

int	iterate_tricorn(t_dxy z)
{
	int		iterations;
	t_dxy	tmp;
	t_dxy	p;

	p = z;
	z.x = 0;
	z.y = 0;
	iterations = 0;
	while (sqrt(z.x * z.x + z.y * z.y) <= 2.0 && iterations <= MAX_ITERATION)
	{
		tmp.x = z.x;
		tmp.y = z.y;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + p.x;
		z.y = -2 * tmp.x * tmp.y + p.y;
		iterations++;
	}
	return (iterations);
}
