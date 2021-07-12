#include "../fractol.h"

static int	ft_atoi(const char *str)
{
	long double	sign;
	long double	number;

	number = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= 48 && *str <= 57)
		number = number * 10 + (*str++ - '0');
	if (number * sign > INT_MAX)
		return (-1);
	if (number * sign < INT_MIN)
		return (0);
	return (number * sign);
}

unsigned int	julia(t_complex xy, t_conf fconf)
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
	fconf.pow = 2;
	if (argc == 3)
		fconf.c = init_complex(ft_atoi(argv[2]), 0);
	else if (argc == 4)
		fconf.c = init_complex(ft_atoi(argv[2]), ft_atoi(argv[3]));
	else
		fconf.c = init_complex(0.285, -0.01);
	window_loop(&fconf);
}
