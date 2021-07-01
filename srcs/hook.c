// HEADER

#include "fractol.h"

int	hk_key_press(int key, t_mlx *mlx)
{
	if (key == 65307)
		exit_program(mlx);
	return (1);
}

int	hk_button_press(int key, void *ptr)
{
	if (key == 4) // scroll up
		(void)ptr;
	else if (key == 5)
		(void)ptr;
	return (1);
}

int	hk_loop(void *ptr)
{
	(void)ptr;
	return (1);
}
