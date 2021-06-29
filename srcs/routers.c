// HEADER

#include "fractol.h"

void	destroy_mlx(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->ptr, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	// mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->data = NULL;
}

void	launcher(int mode, t_res res)
{
	t_mlx	mlx;

	(void)mode;
	init_mlx(&mlx);
	if (new_win(&mlx, &res))
	{
		init_img(&mlx, res);
		sleep(1);
	}
	destroy_mlx(&mlx);
}
