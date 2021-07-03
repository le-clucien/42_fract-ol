// HEADER

#include "fractol.h"

t_dm	*create_dm(void)
{
	t_dm	*dm;

	dm = NULL;
	dm = (t_dm *)malloc(sizeof(t_dm));
	if (!dm)
		return (NULL);
	dm->mlx = NULL;
	dm->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!dm->mlx)
		return (NULL);
	dm->data = NULL;
	dm->data = (t_data *)malloc(sizeof(t_data));
	if (!dm->data)
		return (NULL);
	dm->res = NULL;
	dm->res = (t_xy *)malloc(sizeof(t_xy));
	if (!dm->res)
		return (NULL);
	return (dm);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->test = 32;
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->data = NULL;
}

void	set_data(t_data *data, int mode)
{
	data->mode = mode;
	data->c.x = -0.5;
	data->c.y = 0.5;
	data->var = 1;
	data->direction = 0;
}

void	launcher(int mode)
{
	t_dm	*dm;

	dm = create_dm();
	if (!dm)
	{
		ft_putstr("error: malloc() failed\n");
		exit_program(dm);
	}
	init_mlx(dm->mlx);
	set_data(dm->data, mode);
	if (new_win(dm->mlx, dm->res))
	{
		init_img(dm->mlx, dm->res);
		mlx_hook(dm->mlx->win, 2, (1L<<0), hk_key_press, dm);
		mlx_hook(dm->mlx->win, 3, (1L<<1), hk_key_release, dm);
		mlx_hook(dm->mlx->win, 4, (1L<<2), hk_key_press, dm);
		mlx_hook(dm->mlx->win, 17, (1L << 17), exit_program, dm);
		mlx_loop_hook(dm->mlx->ptr, hk_loop, dm);
		mlx_loop(dm->mlx->ptr);
	}
	exit_program(dm);
}
