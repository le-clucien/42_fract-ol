/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucien <clucien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:30:44 by clucien           #+#    #+#             */
/*   Updated: 2021/07/12 17:30:46 by clucien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_type(int *type, char *arg)
{
	if (!ft_strcmp("JULIA", ft_toupper(arg)))
		*type = JULIA;
	else if (!ft_strcmp("MANDELBROT", ft_toupper(arg)))
		*type = MANDELBROT;
	else if (!ft_strcmp("TRICORN", ft_toupper(arg)))
		*type = TRICORN;
	else
		return (ft_ret_msg("error: unknown error\n", 0));
	return (1);
}

t_dxy	get_constant(int ac, char **av)
{
	t_dxy	out;
	int		tmp;

	tmp = 0;
	out.x = CONSTANT_R;
	out.y = CONSTANT_I;
	if (ac == 3)
	{
		ft_atoi(av[2], &tmp);
		out.x += tmp * CONST_INC;
		out.y += tmp * CONST_INC;
	}
	return (out);
}
