#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

/*
** Data structure for minilibX images
*/

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int 	endian;
} t_img;


# include "complex/complx.h"

#endif