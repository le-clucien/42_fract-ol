// HEADER

#include "fractol.h"

int	init_img(t_mlx *mlx, t_res res)
{
	mlx->img = mlx_new_image(mlx->ptr, res.x, res.y);
	if (!mlx->img)
		return (ft_ret_msg("error: mlx_new_image() failed\n", 0));
	mlx->data = (int *)mlx_get_data_addr(mlx->ptr, &mlx->bpp, &mlx->size_l, &mlx->endian);
	if (!mlx->data)
		return (ft_ret_msg("error: mlx_det_data_addr() failed\n", 0));
	return (1);
}

int	new_win(t_mlx *mlx, t_res *res)
{
	t_res	screen;

	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (ft_ret_msg("error: mlx_init() failed\n", 0));
	screen.x = 0;
	screen.y = 0;
	mlx_get_screen_size(mlx->ptr, &screen.x, &screen.y);
	if (res->x == 1 || res->x > screen.x)
		res->x = screen.x;
	if (res->y == 1 || res->y > screen.y)
		res->y = screen.y;
	mlx->win = mlx_new_window(mlx->ptr, res->x, res->y, "fract-ol");
	if (!mlx->win)
		ft_ret_msg("error: mlx_new_window() failed\n", 0);
	return (1);
}
