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
		mlx_hook(mlx.win, 2, 1, hk_key_press, NULL);
		mlx_hook(mlx.win, 3, 2, hk_key_release, NULL);
		mlx_hook(mlx.win, 17, (1L << 17), exit_program, &mlx);
		mlx_loop_hook(mlx.ptr, hk_loop, NULL);
		mlx_loop(mlx.ptr);
	}
	exit_program(&mlx);
}
