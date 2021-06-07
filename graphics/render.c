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

	range = COLOR_RANGE;
	diff = (conf.color2 - conf.color1) / 6;
	return (conf.color1 * (diff * (n % 6)));
}

static t_complex map(t_complex coords, t_conf conf)
{
	coords.real = (coords.real * 2 / WIDTH) * conf.zoom + (conf.xsum * conf.zoom);
	coords.imag = (coords.imag * 2 / HEIGHT) * conf.zoom + (conf.xsum * conf.zoom);
	return (coords);
}

void	show_fractal(t_img img, t_conf *conf)
{
	unsigned int	color;
	t_complex		n;

	printf("Por aqui pasa\n");
	getchar();
    for (n.imag = 0; n.imag <= HEIGHT; n.imag++) {
		for (n.real = 0; n.real <= WIDTH; n.real++) {
			color = conf->f(map(n, *conf), *conf);
			color = select_color(*conf, color);
			if (color)
				write_pixel(img, n.real, n.imag, color);
		}
	}
}
