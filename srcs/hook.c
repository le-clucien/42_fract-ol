/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:29:06 by clucien           #+#    #+#             */
/*   Updated: 2021/07/12 17:29:10 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hk_key_press(int key, t_dm *dm)
{
	if (key == 65307)
		exit_program(dm);
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
	(void)x;
	(void)y;
	if (key == 4 || key == 5)
	{
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
