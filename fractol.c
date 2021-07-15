#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Wrong, try:\n./fractol mandelbrot\nor\n./fratol julia\n");
		printf("or\n./fratol burning\n");
	}
	else if (!ft_strncmp("mandelbrot", argv[1], 11))
		mandelbrot_conf();
	else if (!ft_strncmp("julia", argv[1], 6))
		julia_conf(argc, argv);
	else if (!ft_strncmp("burning", argv[1], 8))
		burning_conf();
	else
	{
		printf("Wrong, try:\n./fractol mandelbrot\nor\n./fratol julia\n");
		printf("or\n./fratol burning\n");
	}
	return (0);
}
