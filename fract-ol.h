#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "complex/complx.h"

/*
** WINDOW CONFIGURATION
*/

# define WIDTH 1280
# define HEIGHT 720
# define ZOOM 0.8

/*
** ORIGIN CONFIGURATION
** La siguiente formula se aplicara  a las coordenadas utilizando los parametros de abajo:
**
*/
# define COLOR_RANGE	6
# define PRECISION  	100


/*
** Data structure for minilibX images
*/

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int 	endian;
} t_img;

/*
** Data structure for fractals functions
*/

typedef struct s_conf
{
	unsigned int (*f)(t_complex coords, struct s_conf fconf);
	int	pow;
	t_complex c;

	double	xsum;
	double	ysum;
	double 	zoom;
	int		color1;
	int		color2;
} t_conf;


void	mandelbrot_conf(int argc, char **argv);

void	window_loop(t_conf *frac);

void	show_fractal(t_img img, t_conf *conf);

#endif