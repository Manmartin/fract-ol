#include "../fract-ol.h"

unsigned int julia(t_complex xy, t_conf fconf)
{
	t_complex	c;
	t_complex	z;
	int			max_it;

	max_it = PRECISION;
	z = init_complex(xy.real, xy.imag);
	c = fconf.c;
	while (max_it--)
	{
		z = pow_complex(z, fconf.pow);
		z = add_complex(z, c);
		if (z.real * z.real + z.imag * z.imag > 4)
			return (PRECISION - max_it);
	}
	return (0);
}

void	julia_conf(int argc, char **argv)
{
	t_conf	fconf;

	fconf.f = &julia;
	fconf.c = init_complex(0.285, -0.01);
	fconf.pow = 2;
	window_loop(&fconf);
}