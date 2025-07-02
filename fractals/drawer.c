#include "../include/fractol.h"

static void	init_image(t_app *app)
{
	if (app->img)
		mlx_destroy_image(app->mlx, app->img);
	app->img = mlx_new_image(app->mlx, WIN_WIDTH, WIN_HEIGHT);
	app->img_data = mlx_get_data_addr(app->img, &app->bpp,
			&app->size_line, &app->endian);
}

static int	ft_iter_value(t_app *app, double cx, double cy)
{
	if (app->type == MANDELBROT)
		return (mandelbrot(cx, cy));
	else if (app->type == BURNING_SHIP)
		return (burning_ship(cx, cy));
	else
		return (julia(cx, cy, app->julia_re, app->julia_im));
}

static void	render_fractal_pixels(t_app *app)
{
	int		x;
	int		y;
	int		iter;
	double	cx;
	double	cy;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			cx = (x - WIN_WIDTH / 2.0) * (4.0 / (app->zoom * WIN_WIDTH))
				+ app->offset_x;
			cy = (y - WIN_HEIGHT / 2.0) * (4.0 / (app->zoom * WIN_HEIGHT))
				+ app->offset_y;
			iter = ft_iter_value(app, cx, cy);
			put_pixel(app, x, y, get_color(iter, app->color_shift));
			x++;
		}
		y++;
	}
}

void	render_fractal(t_app *app)
{
	init_image(app);
	render_fractal_pixels(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}
