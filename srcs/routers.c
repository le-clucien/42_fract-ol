// HEADER

#include "fractol.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->data = NULL;
}

void	set_data(t_data *data, int mode)
{
	data->mode = mode;
	data->cx = -0.5;
	data->cz = 0.5;
}

void	launcher(int mode)
{
	t_data	data;
	t_res	res;
	t_mlx	mlx;
	t_dm	dm;

	dm.m = &mlx;
	dm.d = &data;
	init_mlx(&mlx);
	set_data(&data, mode);
	if (new_win(&mlx, &res))
	{
		init_img(&mlx, res);
		mlx_hook(mlx.win, 2, (1L<<0), hk_key_press, &dm);
		mlx_hook(mlx.win, 4, (1L<<2), hk_button_press, &dm);
		mlx_hook(mlx.win, 17, (1L << 17), exit_program, &mlx);
		mlx_loop_hook(mlx.ptr, hk_loop, &dm);
		mlx_loop(mlx.ptr);
	}
	exit_program(&mlx);
}
