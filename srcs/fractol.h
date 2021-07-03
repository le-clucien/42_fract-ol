// HEADER

#ifndef FRACTOL_H
# define FRACTOL_H

# define JULIA 1
# define MANDELBROT 2
# define FSLEEP 700
# define SCREEN_BORDER 400

# include "../libft/libft.h"
# include "../minilibX/mlx.h"

# include <math.h>

# include <stdio.h> // oui

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_mlx
{
	int			test;
	void		*ptr;
	void		*win;
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_mlx;

typedef struct	s_data
{
	char		direction;
	int			mode;
	t_xy		c; // constant
	int			var;
}				t_data;

typedef struct	s_dm
{
	t_mlx		*mlx;
	t_data		*data;
	t_xy		*res;
}				t_dm;

void			draw_fractal(t_dm *dm);

int				hk_key_press(int key, t_dm *dm);
int				hk_key_release(int key, t_dm *dm);
int				hk_button_press(int key, t_dm *dm);
int				hk_loop(t_dm *dm);

int				exit_program(t_dm *dm);
void			launcher(int mode);

int				new_win(t_mlx *mlx, t_xy *res);
int				init_img(t_mlx *mlx, t_xy *res);

#endif
