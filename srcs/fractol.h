// HEADER

#ifndef FRACTOL_H
# define FRACTOL_H

# define SCREEN_BORDER 400
# define MAX_ITERATION 255
# define CONST_INC 0.05
// # define HOOK_SLEEP 5000

# define JULIA 1
# define MANDELBROT 2

# include "../libft/libft.h"
# include "../minilibX/mlx.h"

# include <math.h>

# include <stdio.h> // oui

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	 s_dxy
{
	double		x;
	double		y;
}				t_dxy;

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

typedef struct	s_data
{
	int			type;
	double		zoom;
	t_dxy		move;
	t_dxy		c; // constant
}				t_data;

typedef struct	s_res
{
	t_xy		d;
	t_dxy		f;
}				t_res;


typedef struct	s_dm
{
	t_mlx		*mlx;
	t_data		*data;
	t_res		*res;
}				t_dm;

void			draw_fractal(t_dm *dm);

int				hk_key_press(int key, t_dm *dm);
int				hk_key_release(int key, t_dm *dm);
int				hk_button_press(int key, t_dm *dm);
int				hk_loop(t_dm *dm);

int				iterate_julia(t_dxy z, t_dxy c);
int				iterate_mandelbrot(t_dxy z);

int				get_type(int *type, char *arg);

int				exit_program(t_dm *dm);
int				exit_program_msg(t_dm *dm, char *str);

void			launcher(int ac, char **av);

int				new_win(t_mlx *mlx, t_res *res);
int				init_img(t_mlx *mlx, t_xy *res);

#endif
