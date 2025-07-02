#include "../include/fractol.h"

static void	initialize_app(t_app *app)
{
	app->zoom = 1.0;
	app->offset_x = 0.0;
	app->offset_y = 0.0;
	app->img = NULL;
	app->img_data = NULL;
	app->bpp = 0;
	app->size_line = 0;
	app->endian = 0;
	app->color_shift = 0;
}

// the mlx new window: mlx pointer / width / length / title 
int	init_window(t_app *app)
{
	initialize_app(app);
	app->mlx = mlx_init();
	if (!app->mlx)
		return (perror("mlx_init"), 0);
	app->win = mlx_new_window(app->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!app->win)
		return (perror("mlx_new_window"), 0);
	return (1);
}
