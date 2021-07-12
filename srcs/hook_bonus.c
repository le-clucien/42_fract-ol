/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:29:21 by clucien           #+#    #+#             */
/*   Updated: 2021/07/12 17:29:24 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hk_key_press(int key, t_dm *dm)
{
	if (key == 65307)
		exit_program(dm);
	else if (key == 97 || key == 115)
		dm->data->color_shift += (key - 106);
	else if (key == 65362 || key == 65364)
		dm->data->move.y += (key - 65363) * (0.1 / (dm->data->zoom / 2));
	else if (key == 65361 || key == 65363)
		dm->data->move.x += (key - 65362) * (0.1 / (dm->data->zoom / 2));
	if (key == 119 || key == 113)
	{
		dm->data->c.x += CONST_INC * ((key - 116) / 3);
		dm->data->c.y += CONST_INC * ((key - 116) / 3);
	}
	draw_fractal(dm);
	return (1);
}

int	hk_key_release(int key, t_dm *dm)
{
	(void)key;
	(void)dm;
	return (1);
}

int	hk_button_press(int key, int x, int y, t_dm *dm)
{
	t_dxy	rad;

	if (key == 4 || key == 5)
	{
		rad.x = (double)x / dm->res->f.x;
		rad.y = (double)y / dm->res->f.y;
		dm->data->move.x += (rad.x - 0.5) * 2 * (0.1 / (dm->data->zoom / 2));
		dm->data->move.y += (rad.y - 0.5) * 2 * (0.1 / (dm->data->zoom / 2));
		if (key == 4)
			dm->data->zoom += 1 * (dm->data->zoom / 9);
		if (key == 5)
			dm->data->zoom -= 1 * (dm->data->zoom / 9);
		draw_fractal(dm);
	}
	return (1);
}

int	hk_loop(t_dm *dm)
{
	(void)dm;
	return (1);
}
