#include "../fract-ol.h"

void    write_pixel(t_img img, int x, int y, unsigned int color)
{
    char    *pixel;

    pixel = img.addr + y * img.size_line + x * (img.bpp / 8);
    *(unsigned int *)pixel = color;
}

unsigned int	select_color(t_conf conf, unsigned int n)
{
	int diff;
	int	range;

	if (n == 0)
		return (0);
	range = COLOR_RANGE;
	diff = (conf.color2 - conf.color1) / 6;
	return (conf.color1 * (diff * (n % 6)));
}

static t_complex map(t_complex coords, t_conf conf)
{
	coords.real = (coords.real * 2 / WIDTH) * conf.zoom + (conf.xsum * conf.zoom);
	coords.imag = (coords.imag * 2 / HEIGHT) * conf.zoom + (conf.ysum * conf.zoom);
	return (coords);
}

void	show_fractal(t_conf *conf)
{
	unsigned int	color;
	t_complex		n;

	n = init_complex(0, 0);
	while (n.imag <= HEIGHT)
	{
		while (n.real <= WIDTH)
		{
			color = select_color(*conf, conf->f(map(n, *conf), *conf));
			write_pixel(conf->img, n.real, n.imag, color);
			n.real++;
		}
		n.real = 0;
		n.imag++;
	}
	mlx_put_image_to_window(conf->mlx, conf->window, conf->img.img,0, 0);
}
