// HEADER

#include "fractol.h"

int	hk_scroll_up(int key, void *ptr)
{
	(void)ptr;
	printf("press: %d\n", key);
	return (1);
}

int	hk_scroll_down(int key, void *ptr) // ?
{
	(void)ptr;
	printf("press: %d\n", key);
	return (1);
}

int	hk_loop(void *ptr)
{
	(void)ptr;
	return (1);
}
