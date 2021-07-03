// HEADER

#include "fractol.h"

int	hk_key_press(int key, t_dm *dm)
{
	if (key == 65362)
		dm->data->direction = 1;
	else if (key == 65364)
		dm->data->direction = -1;
	else if (key == 65307)
		exit_program(dm);
	return (1);
}

int	hk_key_release(int key, t_dm *dm)
{
	if (key == 65362 || key == 65364)
		dm->data->direction = 0;
	return (1);
}

int	hk_button_press(int key, t_dm *dm)
{
	// HUGE UNLINKING ISSUE WITH *dm
	if (key == 4)
		draw_fractal(dm);
	else if (key == 5)
		draw_fractal(dm);
	return (1);
}

int	hk_loop(t_dm *dm)
{
	t_xy	s;

	s.x = -1;
	while (++s.x < FSLEEP)
	{
		s.y = -1;
		while (++s.y < FSLEEP)
			;
	}
	if (dm->data->direction != 0)
	{
		draw_fractal(dm);
		mlx_put_image_to_window(dm->mlx->ptr, dm->mlx->win, dm->mlx->img, 0, 0);
		dm->data->var += dm->data->direction * 10;
	}
	return (1);
}
