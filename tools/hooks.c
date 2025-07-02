#include "../include/fractol.h"

static void	clean_exit(int exit_code, t_app *app)
{
	if (!app)
		exit(exit_code);
	if (app->img)
		mlx_destroy_image(app->mlx, app->img);
	if (app->win && app->mlx)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
	{
		mlx_loop_end(app->mlx);
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	exit(exit_code);
}

static int	close_win(t_app *app)
{
	clean_exit(0, app);
	return (0);
}

static int	key_hook(int keycode, t_app *app)
{
	if (keycode == EXIT)
		close_win(app);
	else if (keycode == UP_KEY)
		app->offset_y -= MOVE_STEP / app->zoom;
	else if (keycode == DOWN_KEY)
		app->offset_y += MOVE_STEP / app->zoom;
	else if (keycode == LEFT_KEY)
		app->offset_x -= MOVE_STEP / app->zoom;
	else if (keycode == RIGHT_KEY)
		app->offset_x += MOVE_STEP / app->zoom;
	else if (keycode == ZOOM_IN_KEY)
		app->zoom *= ZOOM_FACTOR;
	else if (keycode == ZOOM_OUT_KEY)
		app->zoom /= ZOOM_FACTOR;
	else if (keycode == KEY_COLOR_SHIFT)
		app->color_shift += 5;
	else if (keycode == JULIA_LEFT && app->type == JULIA)
		app->julia_re -= 0.01;
	else if (keycode == JULIA_RIGHT && app->type == JULIA)
		app->julia_re += 0.01;
	else if (keycode == JULIA_UP && app->type == JULIA)
		app->julia_im += 0.01;
	else if (keycode == JULIA_DOWN && app->type == JULIA)
		app->julia_im -= 0.01;
	return (render_fractal(app), 0);
}

static int	mouse_hook(int button, int x, int y, void *param)
{
	t_app	*app;
	double	old_cx;
	double	old_cy;

	app = (t_app *)param;
	if (button != MOUSE_SCROLL_UP && button != MOUSE_SCROLL_DOWN)
		return (0);
	old_cx = (x - WIN_WIDTH / 2.0) * (4.0 / (app->zoom * WIN_WIDTH))
		+ app->offset_x;
	old_cy = (y - WIN_HEIGHT / 2.0) * (4.0 / (app->zoom * WIN_HEIGHT))
		+ app->offset_y;
	if (button == MOUSE_SCROLL_UP)
		app->zoom *= ZOOM_FACTOR;
	else if (button == MOUSE_SCROLL_DOWN)
		app->zoom /= ZOOM_FACTOR;
	app->offset_x = old_cx - (x - WIN_WIDTH / 2.0)
		* (4.0 / (app->zoom * WIN_WIDTH));
	app->offset_y = old_cy - (y - WIN_HEIGHT / 2.0)
		* (4.0 / (app->zoom * WIN_HEIGHT));
	render_fractal(app);
	return (0);
}

// the close win belongs to the x in the window
// 17 for destroy notify for window close
// 2 keyboard press
// 1 or 1L << 0 ==> Bitmask for Keypress matching
// with buttonpress and buttonrelease
// MLX uses bitmasks to tell the event system which events you're interested in.
void	setup_hooks(t_app *app)
{
	mlx_hook(app->win, 17, 0, close_win, app);
	mlx_hook(app->win, 2, 1, key_hook, app);
	mlx_mouse_hook(app->win, mouse_hook, app);
}
