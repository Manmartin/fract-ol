#include "../fractol.h"
#include <mlx.h>

void	write_pixel(t_img img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img.addr + y * img.size_line + x * (img.bpp / 8);
	*(unsigned int *)pixel = color;
}

unsigned int	select_color(t_conf conf, unsigned int n)
{
	int	diff;

	if (n == 0)
		return (0);
	diff = (conf.color2 - conf.color1) / COLOR_RANGE;
	return (conf.color1 * (diff * (n % COLOR_RANGE)));
}

static t_complex	map(t_complex coords, t_conf conf)
{
	coords.real = ((coords.real * 4 / WIDTH) - 2) * conf.zoom + conf.xsum;
	coords.imag = ((coords.imag * 4 / HEIGHT) - 2) * conf.zoom + conf.ysum;
	return (coords);
}

void	show_fractal(t_conf *conf)
{
	unsigned int	color;
	t_complex		n;

	n = init_complex(0, 0);
	while (n.imag < HEIGHT)
	{
		while (n.real < WIDTH)
		{
			color = select_color(*conf, conf->f(map(n, *conf), *conf));
			write_pixel(conf->img, n.real, n.imag, color);
			n.real++;
		}
		n.real = 0;
		n.imag++;
	}
	mlx_clear_window(conf->mlx, conf->window);
	mlx_put_image_to_window(conf->mlx, conf->window, conf->img.img, 0, 0);
}
