#include "../include/fractol.h"

int	julia(double zx, double zy, double cx, double cy)
{
	double	zx2;
	double	zy2;
	int		iter;

	iter = 0;
	while (iter < MAX_ITER)
	{
		zx2 = zx * zx;
		zy2 = zy * zy;
		if (zx2 + zy2 > 4.0)
			break ;
		zy = 2.0 * zx * zy + cy;
		zx = zx2 - zy2 + cx;
		iter++;
	}
	return (iter);
}
