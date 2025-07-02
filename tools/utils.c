#include "../include/fractol.h" 

void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia <real> <imag>\n");
	ft_printf("  ./fractol burning_ship\n");
}

static int	validate_julia_args(int argc, char **argv, t_app *app)
{
	if (argc != 4)
		return (print_usage(), 0);
	if (!ft_is_valid_float(argv[2]) || !ft_is_valid_float(argv[3]))
	{
		ft_printf("Invalid float input for Julia set.\n");
		print_usage();
		return (0);
	}
	app->julia_re = ft_atof(argv[2]);
	app->julia_im = ft_atof(argv[3]);
	if (app->julia_re == DBL_MAX || app->julia_re == -DBL_MAX
		|| app->julia_im == DBL_MAX || app->julia_im == -DBL_MAX)
	{
		ft_printf("Julia set parameters are too large.\n");
		print_usage();
		return (0);
	}
	return (1);
}

int	check_args(int argc, char **argv, t_app *app)
{
	if (argc < 2)
	{
		print_usage();
		return (0);
	}
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
		app->type = MANDELBROT;
	else if (ft_strncmp(argv[1], "burning_ship", ft_strlen(argv[1])) == 0)
		app->type = BURNING_SHIP;
	else if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
	{
		if (validate_julia_args(argc, argv, app) == 0)
			return (0);
		app->type = JULIA;
	}
	else
	{
		ft_printf("Invalid fractal type: %s\n", argv[1]);
		print_usage();
		return (0);
	}
	return (1);
}
