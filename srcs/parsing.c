// HEADER

#include "fractol.h"

int		get_type(int *type, char *arg)
{
	if (!ft_strcmp("JULIA", ft_toupper(arg)))
		*type = JULIA;
	else if (!ft_strcmp("MANDELBROT", ft_toupper(arg)))
		*type = MANDELBROT;
	else
		return (ft_ret_msg("error: invalid fractal type\n", 0));
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
