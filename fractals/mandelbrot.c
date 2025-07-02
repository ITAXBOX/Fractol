#include "../include/fractol.h"

// z = z^2 + c where c = x + iy
// if |z| > 2, the point escape
int	mandelbrot(double x, double y)
{
	double	zx;
	double	zy;
	double	zx2;
	double	zy2;
	int		iter;

	zx = 0.0;
	zy = 0.0;
	iter = 0;
	while (iter < MAX_ITER)
	{
		zx2 = zx * zx;
		zy2 = zy * zy;
		if (zx2 + zy2 > 4.0)
			break ;
		zy = 2.0 * zx * zy + y;
		zx = zx2 - zy2 + x;
		iter++;
	}
	return (iter);
}
