#include "../fract-ol.h"

static void conf_init(t_conf *conf)
{
	conf->xsum = -1;
	conf->ysum = -1;
	conf->zoom = 1;
	conf->color1 = 0x002caadb;
	conf->color2 = 0x00ffbe30;
}


void	window_loop(t_conf *conf)
{
	void    *mlx;
    void    *window;
    t_img   img;

	conf_init(conf);
    mlx = mlx_init();
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
	show_fractal(img, conf);
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "FRACT-OL");
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
}