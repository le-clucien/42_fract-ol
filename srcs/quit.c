// HEADER

#include "fractol.h"

void	destroy_mlx(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->ptr, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
}

int		exit_program(t_mlx *mlx)
{
	destroy_mlx(mlx);
	exit(1);
	return (1);
}
