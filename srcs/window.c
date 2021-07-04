// HEADER

#include "fractol.h"

void	default_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->data = NULL;
}

int	init_img(t_mlx *mlx, t_xy *res)
{
	mlx->img = mlx_new_image(mlx->ptr, res->x, res->y);
	if (!mlx->img)
		return (ft_ret_msg("error: mlx_new_image() failed\n", 0));
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_l, &mlx->endian);
	if (!mlx->data)
		return (ft_ret_msg("error: mlx_det_data_addr() failed\n", 0));
	return (1);
}

int	new_win(t_mlx *mlx, t_res *res)
{
	default_mlx(mlx);
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (ft_ret_msg("error: mlx_init() failed\n", 0));
	mlx_get_screen_size(mlx->ptr, &res->d.x, &res->d.y);
	res->d.x -= SCREEN_BORDER;
	res->d.y -= SCREEN_BORDER;
	res->f.x = (double)res->d.x;
	res->f.y = (double)res->d.y;
	mlx->win = mlx_new_window(mlx->ptr, res->d.x, res->d.y, "fract-ol");
	if (!mlx->win)
		ft_ret_msg("error: mlx_new_window() failed\n", 0);
	return (1);
}
