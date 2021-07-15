#include "../fractol.h"
#include "macros.h"

static void	conf_init(t_conf *conf)
{
	conf->xsum = 0;
	conf->ysum = 0;
	conf->zoom = 1.0;
	conf->range = COLOR_RANGE;
	conf->color1 = 0x002caadb;
	conf->color2 = 0x00ffbe30;
}

static int	zoom(int kikoff, int x, int y, t_conf *conf)
{
	t_complex	center;

	center = map(init_complex(x, y), *conf);
	if (kikoff == 5)
	{
		conf->xsum = center.real;
		conf->ysum = center.imag;
		conf->zoom *= ZOOM;
		show_fractal(conf);
	}
	else if (kikoff == 4)
	{
		conf->xsum = center.real;
		conf->ysum = center.imag;
		conf->zoom /= ZOOM;
		show_fractal(conf);
	}
	return (0);
}

static void	color_shift(t_conf *conf)
{
	if (conf->range == 6)
		conf->range = 16;
	else
		conf->range = 6;
	show_fractal(conf);
}

static int	move(int kikoff, t_conf *conf)
{
	if (kikoff == KEY_UP)
	{
		conf->ysum -= MOVEMENT * conf->zoom;
		show_fractal(conf);
	}
	else if (kikoff == KEY_DOWN)
	{
		conf->ysum += MOVEMENT * conf->zoom;
		show_fractal(conf);
	}
	else if (kikoff == KEY_LEFT)
	{
		conf->xsum -= MOVEMENT * conf->zoom;
		show_fractal(conf);
	}
	else if (kikoff == KEY_RIGHT)
	{
		conf->xsum += MOVEMENT * conf->zoom;
		show_fractal(conf);
	}
	else if (kikoff == KEY_P)
		color_shift(conf);
	else if (kikoff == KEY_ESCAPE)
		exit (0);
	return (0);
}

void	window_loop(t_conf *conf)
{
	t_img	img;

	conf_init(conf);
	conf->mlx = mlx_init();
	img.img = mlx_new_image(conf->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img,
			&img.bpp, &img.size_line, &img.endian);
	conf->window = mlx_new_window(conf->mlx, WIDTH, HEIGHT, "FRACT-OL");
	conf->img = img;
	show_fractal(conf);
	mlx_hook(conf->window, KEYPRESS, 0, move, conf);
	mlx_hook(conf->window, 4, 1L << 8, zoom, conf);
	mlx_loop(conf->mlx);
}
