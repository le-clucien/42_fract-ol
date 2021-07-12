/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:32:04 by clucien           #+#    #+#             */
/*   Updated: 2021/07/12 17:32:06 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_dm	*create_dm(void)
{
	t_dm	*dm;

	dm = NULL;
	dm = (t_dm *)malloc(sizeof(t_dm));
	if (!dm)
		return (NULL);
	dm->mlx = NULL;
	dm->data = NULL;
	dm->res = NULL;
	dm->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!dm->mlx)
		return (NULL);
	dm->data = (t_data *)malloc(sizeof(t_data));
	if (!dm->data)
		return (NULL);
	dm->res = (t_res *)malloc(sizeof(t_res));
	if (!dm->res)
		return (NULL);
	return (dm);
}

void	set_data(t_dm *dm, int ac, char **av)
{
	(void)ac;
	if (!get_type(&dm->data->type, av[1]))
		exit_program(dm);
	dm->data->c = get_constant(ac, av);
	dm->data->zoom = 1.0;
	dm->data->move.x = 0.0;
	dm->data->move.y = 0.0;
	dm->data->color_shift = 0;
}

void	mlx_looper(t_dm *dm)
{
	mlx_hook(dm->mlx->win, 2, (1L << 0), hk_key_press, dm);
	mlx_hook(dm->mlx->win, 3, (1L << 1), hk_key_release, dm);
	mlx_hook(dm->mlx->win, 4, (1L << 2), hk_button_press, dm);
	mlx_hook(dm->mlx->win, 17, (1L << 17), exit_program, dm);
	mlx_loop_hook(dm->mlx->ptr, hk_loop, dm);
	mlx_loop(dm->mlx->ptr);
}

void	launcher(int ac, char **av)
{
	t_dm	*dm;

	dm = create_dm();
	if (!dm)
		exit_program_msg(dm, "error: malloc() failed\n");
	set_data(dm, ac, av);
	if (new_win(dm->mlx, dm->res))
	{
		init_img(dm->mlx, &dm->res->d);
		draw_fractal(dm);
		mlx_looper(dm);
	}
	exit_program(dm);
}
