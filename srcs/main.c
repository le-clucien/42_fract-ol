// HEADER

#include "fractol.h"

int	read_args(int ac, char **av)
{
	int	mode;

	(void)ac;
	if (!ft_strcmp("JULIA", ft_toupper(av[1])))
		mode = JULIA;
	else if (!ft_strcmp("MANDELBROT", ft_toupper(av[1])))
		mode = MANDELBROT;
	else
		return (ft_ret_msg("error: invalid arg for fractal type\n", 0));
	return (mode);
}

int	main(int ac, char **av)
{
	int		mode;

	if (ac < 2)
	{
		ft_putstr("syntax: ./fract-ol <FRACTAL_TYPE> (<C_VALUE>)\n");
		ft_putstr("Available types:\n - Julia\n - Mandelbrot\n");
		return (1);
	}
	// C_VALUE to do
	mode = read_args(ac, av);
	if (mode)
		launcher(mode);
	return (0);
}
