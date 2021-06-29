// HEADER

#include "fractol.h"

int	read_args(int ac, char **av, t_res *res)
{
	int	mode;

	if (!ft_strcmp("JULIA", ft_toupper(av[1])))
		mode = JULIA;
	else if (!ft_strcmp("MANDELBROT", ft_toupper(av[1])))
		mode = MANDELBROT;
	else
		return (ft_ret_msg("error: invalid arg for fractal type\n", 0));
	if (ac == 2)
		return (mode);
	if (ac >= 3 && !ft_atoi(av[2], &res->x))
		return (ft_ret_msg("error: invalid arg for resolution\n", 0));
	if (ac == 3)
		res->y = res->x;
	else if (ac == 4 && !ft_atoi(av[3], &res->y))
		return (ft_ret_msg("error: invalid arg for resolution\n", 0));
	return (1);
}

int	main(int ac, char **av)
{
	t_res	res;
	int		mode;

	if (ac < 2)
		return (ft_ret_msg("syntax: ./fract-ol <FRACTAL_TYPE> (<RES_X> <RES_Y>)\n", 1));
	res.x = 1;
	res.y = 1;
	mode = read_args(ac, av, &res);
	if (mode)
		launcher(mode, res);
	return (0);
}
