// HEADER

#ifndef FRACTOL_H
# define FRACTOL_H

# define JULIA 1
# define MANDELBROT 2

# include "../libft/libft.h"
# include "../minilibX/mlx.h"

# include <math.h>

# include <stdio.h> //

typedef struct	s_res
{
	int			x;
	int			y;
}				t_res;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_mlx;

int				hk_key_press(int key, void *ptr);
int				hk_key_release(int key, void *ptr);
int				hk_loop(void *ptr);

int				exit_program(t_mlx *mlx);
void			launcher(int mode, t_res res);

int				new_win(t_mlx *mlx, t_res *res);
int				init_img(t_mlx *mlx, t_res res);

#endif
