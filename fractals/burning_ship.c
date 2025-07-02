#include "../include/fractol.h"

int	burning_ship(double cx, double cy)
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
		if (zx < 0)
			zx = -zx;
		if (zy < 0)
			zy = -zy;
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
