// HEADER

#include "fractol.h"

int	print_syntax(void)
{
	ft_putstr("syntax: ./fract-ol <FRACTAL_TYPE> (flags)\n");
	ft_putstr("Available types (case ignored):\n Julia\n Mandelbrot\n");
	ft_putstr("Available flags:\n");
	return (1);
}

int	check_syntax(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!ft_is_str_alpha(av[1]))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (!check_syntax(ac, av))
		return (print_syntax());
	launcher(ac, av);
	return (0);
}
