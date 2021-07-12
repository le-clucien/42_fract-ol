/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:31:25 by clucien           #+#    #+#             */
/*   Updated: 2021/07/12 17:31:37 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_mlx(t_dm *dm)
{
	if (dm->mlx->img)
		mlx_destroy_image(dm->mlx->ptr, dm->mlx->img);
	if (dm->mlx->win)
		mlx_destroy_window(dm->mlx->ptr, dm->mlx->win);
	if (dm->mlx->ptr)
	{
		mlx_destroy_display(dm->mlx->ptr);
		free(dm->mlx->ptr);
	}
	free(dm->mlx);
}

int	exit_program(t_dm *dm)
{
	if (!dm)
		exit(1);
	if (dm->mlx)
		destroy_mlx(dm);
	if (dm->data)
		free(dm->data);
	if (dm->res)
		free(dm->res);
	free(dm);
	exit(1);
	return (1);
}

int	exit_program_msg(t_dm *dm, char *str)
{
	ft_putstr(str);
	exit_program(dm);
	return (1);
}
