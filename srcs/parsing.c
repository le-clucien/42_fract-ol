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

int		get_type(int *type, char *arg)
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

int		get_constant(t_dxy *c, char ac, char **av) // template
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-c") || !ft_strcmp(av[i], "--complex"))
		{
			(void)c;
			break ;
		}
	}
	return (1);
}
