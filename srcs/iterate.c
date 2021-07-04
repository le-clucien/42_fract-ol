// HEADER

#include "fractol.h"

int		iterate_julia(t_dxy z, t_dxy c)
{
	int		iterations;
	double	x_tmp;

	iterations = 0;
	while (sqrt(z.x * z.x + z.y * z.y) <= 2.0 && iterations < MAX_ITERATION)
	{
		x_tmp = z.x * z.x - z.y * z.y;
		z.y = 2 * z.x * z.y + c.y;
		z.x = x_tmp + c.x;
		iterations++;
	}
	return (iterations);
}
