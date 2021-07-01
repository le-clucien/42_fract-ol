// HEADER

#include "fractol.h"

int	hk_key_press(int key, t_dm *dm)
{
	if (key == 65307)
		exit_program(dm->m);
	return (1);
}

int	hk_button_press(int key, t_dm *dm)
{
	if (key == 4) // scroll up
		draw_in(dm);
	// else if (key == 5) // scroll down
	// 	draw_out(dm);
	return (1);
}

int	hk_loop(t_dm *dm)
{
	printf("value: %d\n", dm->d->mode);
	return (1);
}
