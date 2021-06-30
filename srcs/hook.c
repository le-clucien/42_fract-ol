// HEADER

#include "fractol.h"

int	hk_key_press(int key, void *ptr)
{
	(void)ptr;
	printf("press: %d\n", key);
	return (1);
}

int	hk_key_release(int key, void *ptr)
{
	(void)ptr;
	printf("release: %d\n", key);
	return (1);
}

int	hk_loop(void *ptr)
{
	(void)ptr;
	return (1);
}
