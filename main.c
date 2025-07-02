#include "include/fractol.h"

int	main(int argc, char **argv)
{
	t_app	app;

	if (check_args(argc, argv, &app) == 0)
		return (1);
	if (init_window(&app) == 0)
		return (1);
	setup_hooks(&app);
	render_fractal(&app);
	mlx_loop(app.mlx);
	return (0);
}
