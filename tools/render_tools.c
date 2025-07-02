#include "../include/fractol.h"

void	put_pixel(t_app *app, int x, int y, int color)
{
	int	pixel;

	pixel = (y * app->size_line) + (x * (app->bpp / 8));
	*(unsigned int *)(app->img_data + pixel) = color;
}

// color custimization function
int	get_color(int iter, int shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (0x000000);
	t = (double)(iter + shift) / (double)(MAX_ITER + shift);
	if (t > 1.0)
		t = 1.0;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}
