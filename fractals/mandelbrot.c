#include "../fract-ol.h"

unsigned int mandelbrot(t_complex xy, t_conf fconf)
{
	t_complex	c;
	t_complex	z;
	int			max_it;

	max_it = PRECISION;
	z = fconf.c;
	c = init_complex(xy.real, xy.imag);
	while (max_it--)
	{
		z = pow_complex(z, fconf.pow);
		z = add_complex(z, c);
		if (z.real * z.real + z.imag * z.imag > 4)
			return (PRECISION - max_it);
	}
	return (0);
}

void	mandelbrot_conf(int argc, char **argv)
{
	t_conf	fconf;

	fconf.f = &mandelbrot;
	fconf.c = init_complex(0, 0);
	fconf.pow = 2;
	window_loop(&fconf);
}