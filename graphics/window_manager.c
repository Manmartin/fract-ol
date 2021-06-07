#include "../fract-ol.h"

static void conf_init(t_conf *conf)
{
	conf->xsum = -1;
	conf->ysum = -1;
	conf->zoom = 1;
	conf->color1 = 0x002caadb;
	conf->color2 = 0x00ffbe30;
}


int		zoom(int kikoff, t_conf *conf)
{
	if (kikoff == 112)
	{
		conf->zoom *= ZOOM;
		show_fractal(conf);
	}
	else if (kikoff == 108)
	{
		conf->zoom /= ZOOM;
		show_fractal(conf);
	}
	else if (kikoff == 65362)
	{
		conf->ysum -= MOVEMENT;
		show_fractal(conf);
	}
	else if (kikoff == 65364)
	{
		conf->ysum += MOVEMENT;
		show_fractal(conf);
	}
	else if (kikoff == 65361)
	{
		conf->xsum -= MOVEMENT;
		show_fractal(conf);
	}
	else if (kikoff == 65363)
	{
		conf->xsum += MOVEMENT;
		show_fractal(conf);
	}
	else if (kikoff == 65307)
	{
		mlx_loop_end(conf->mlx);
		exit (0);
	}
}


void	window_loop(t_conf *conf)
{
    t_img   img;

	conf_init(conf);
    conf->mlx = mlx_init();
	img.img = mlx_new_image(conf->mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
	conf->window = mlx_new_window(conf->mlx, WIDTH, HEIGHT, "FRACT-OL");
	conf->img = img;
	show_fractal(conf);
	mlx_key_hook(conf->window, zoom, conf);
	mlx_loop(conf->mlx);
}