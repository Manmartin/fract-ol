#ifndef COMPLX_H
# define COMPLX_H

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

t_complex	init_complex(double real, double imag);
t_complex	add_complex(t_complex n1, t_complex n2);
t_complex	product_complex(t_complex n1, t_complex n2);
t_complex	division_complex(t_complex n1, t_complex n2);
t_complex	pow_complex(t_complex n1, int pow);

#endif