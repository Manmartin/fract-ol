#include "complx.h"

t_complex	init_complex(double real, double imag)
{
	t_complex n;

	n.real = real;
	n.imag = imag;
	return (n);
}

t_complex	add_complex(t_complex n1, t_complex n2)
{
	n1.real += n2.real;
	n1.imag += n2.imag;
	return (n1);
}

t_complex	product_complex(t_complex n1, t_complex n2)
{
	t_complex result;

	result.real = n1.real * n2.real - n1.imag * n2.imag;
	result.imag = n1.real * n2.imag + n1.imag * n2.real;
	return (result);
}

t_complex	division_complex(t_complex n1, t_complex n2)
{
	t_complex result;

	result.real = (n1.real * n2.real + n1.imag * n2.imag) / (n2.real * n2.real + n2.imag + n2.imag);
	result.imag = (n1.imag * n2.real - n1.real * n2.imag) / (n2.real * n2.real + n2.imag + n2.imag);
	return (result);
}

t_complex	pow_complex(t_complex n1, int pow)
{
	t_complex result;

	result = n1;
	while (--pow)
		result = product_complex(result, n1);
	return (result);
}
