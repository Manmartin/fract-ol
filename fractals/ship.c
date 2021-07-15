#include "../fractol.h"

unsigned int	burning(t_complex xy, t_conf fconf)
{
	t_complex	c;
	t_complex	z;
	int			max_it;

	max_it = PRECISION;
	z = fconf.c;
	c = init_complex(xy.real, xy.imag);
	while (max_it--)
	{
		z = init_complex(fabs(z.real), fabs(z.imag));
		z = pow_complex(z, 2);
		z = add_complex(z, c);
		if (z.real * z.real + z.imag * z.imag > 4)
			return (PRECISION - max_it);
	}
	return (0);
}

void	burning_conf(void)
{
	t_conf	fconf;

	fconf.f = &burning;
	fconf.c = init_complex(0, 0);
	fconf.pow = 2;
	window_loop(&fconf);
}
