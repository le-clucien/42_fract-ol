// HEADER

#include "fractol.h"

int	read_args(int ac, char **av, t_res *res)
{
	
}

int	main(int ac, char **av)
{
	t_res	res;
	int		mode;

	if (ac < 2)
		ft_ret_msg("syntax: ./fract-ol <FRACTAL_TYPE> (<RES_X> <RES_Y>)");
	mode = read_args(ac, av, &res);
	if (res.x)
		launcher(mode, res);
	return (0);
}
