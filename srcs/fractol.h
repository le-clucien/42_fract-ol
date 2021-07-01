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

typedef struct	s_data
{
	int			mode;
	double		cx; // constant real
	double		cz; // constant imaginary
	double		px; // position of x radius
	double		py; // position of y radius
}				t_data;

typedef struct	s_dm
{
	t_mlx		*m;
	t_data		*d;
}				t_dm;

void			draw_in(t_dm *dm);

int				hk_key_press(int key, t_dm *dm);
int				hk_button_press(int key, t_dm *dm);
int				hk_loop(t_dm *dm);

int				exit_program(t_mlx *mlx);

int				exit_program(t_mlx *mlx);
void			launcher(int mode);

int				new_win(t_mlx *mlx, t_res *res);
int				init_img(t_mlx *mlx, t_res res);

#endif
