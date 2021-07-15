#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <math.h>

# include "complex/complx.h"

/*
** WINDOW CONFIGURATION
*/

# define WIDTH 600
# define HEIGHT 600
# define ZOOM 0.8

/*
** ORIGIN CONFIGURATION
*/
# define COLOR_RANGE	6
# define PRECISION  	64
# define MOVEMENT		1

/*
** Data structure for minilibX images
*/

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

/*
** Data structure for fractals functions
*/

typedef struct s_conf
{
	unsigned	int	(*f)(t_complex coords, struct s_conf fconf);
	int				pow;
	t_complex		c;

	double			xsum;
	double			ysum;
	double			zoom;

	int				color1;
	int				color2;
	int				range;

	t_img			img;
	void			*mlx;
	void			*window;
}	t_conf;

void		mandelbrot_conf(void);
void		julia_conf(int argc, char **argv);
void		burning_conf(void);

void		window_loop(t_conf *frac);

t_complex	map(t_complex coords, t_conf conf);
void		show_fractal(t_conf *conf);

#endif