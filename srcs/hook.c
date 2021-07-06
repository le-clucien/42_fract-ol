// HEADER

#include "fractol.h"

int	hk_key_press(int key, t_dm *dm)
{
	// printf("%d\n", key);
	// return (1);
	if (key == 65362 || key == 65364)
	{
		// replace by move.x
		dm->data->zoom += key - 65363;
		draw_fractal(dm);
	}
	if (key == 65361 || key == 65363)
	{
		dm->data->move.y += key - 65362;
		draw_fractal(dm);
	}
	if (key == 119 || key == 113)
	{
		dm->data->c.x += CONST_INC * ((key - 116) / 3);
		dm->data->c.y += CONST_INC * ((key - 116) / 3);
		draw_fractal(dm);
	}
	else if (key == 65307)
		exit_program(dm);
	return (1);
}

int	hk_key_release(int key, t_dm *dm)
{
	(void)key;
	(void)dm;
	return (1);
}

int	hk_button_press(int key, t_dm *dm)
{
	// HUGE UNLINKING ISSUE WITH *dm in mlx hook
	if (key == 4)
		draw_fractal(dm);
	else if (key == 5)
		draw_fractal(dm);
	return (1);
}

int	hk_loop(t_dm *dm)
{
	(void)dm;
	// t_xy	s;

	// s.x = -1;
	// while (++s.x < HOOK_SLEEP)
	// {
	// 	s.y = -1;
	// 	while (++s.y < HOOK_SLEEP)
	// 		;
	// }
	return (1);
}
