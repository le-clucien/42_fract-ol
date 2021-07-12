/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:33:28 by clucien           #+#    #+#             */
/*   Updated: 2021/07/12 17:33:30 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	default_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->data = NULL;
}

int	init_img(t_mlx *mlx, t_xy *res)
{
	mlx->img = mlx_new_image(mlx->ptr, res->x, res->y);
	if (!mlx->img)
		return (ft_ret_msg("error: mlx_new_image() failed\n", 0));
	mlx->data = (int *)mlx_get_data_addr(
			mlx->img, &mlx->bpp, &mlx->size_l, &mlx->endian);
	if (!mlx->data)
		return (ft_ret_msg("error: mlx_det_data_addr() failed\n", 0));
	return (1);
}

int	set_res(t_mlx *mlx, t_res *res)
{
	if (!mlx_get_screen_size(mlx->ptr, &res->d.x, &res->d.y))
		return (ft_ret_msg("error: () failed\n", 0));
	if (WIDTH != 'F' && WIDTH < res->d.x)
		res->d.x = WIDTH;
	if (HEIGHT != 'F' && HEIGHT < res->d.y)
		res->d.y = HEIGHT;
	res->f.x = (double)res->d.x;
	res->f.y = (double)res->d.y;
	return (1);
}

int	new_win(t_mlx *mlx, t_res *res)
{
	default_mlx(mlx);
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (ft_ret_msg("error: mlx_init() failed\n", 0));
	if (!set_res(mlx, res))
		return (0);
	mlx->win = mlx_new_window(mlx->ptr, res->d.x, res->d.y, "fract-ol");
	if (!mlx->win)
		return (ft_ret_msg("error: mlx_new_window() failed\n", 0));
	return (1);
}
