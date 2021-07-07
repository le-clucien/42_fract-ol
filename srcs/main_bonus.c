// HEADER

#include "fractol.h"

int	print_syntax(void)
{
	ft_putstr("syntax: ./fract-ol <FRACTAL_TYPE>\n");
	ft_putstr("Available types:\n");
	ft_putstr(" - Julia\n - Mandelbrot\n - Tricorn\n");
	return (1);
}

int	check_syntax(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ft_strcmp(ft_toupper(av[1]), "JULIA") &&
			ft_strcmp(ft_toupper(av[1]), "MANDELBROT") &&
			ft_strcmp(ft_toupper(av[1]), "TRICORN"))
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
