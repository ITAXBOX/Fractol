#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../printf/ft_printf.h"
# include <math.h>
# include <float.h> 

# define MAX_ITER 100
# define WIN_WIDTH 1000
# define WIN_HEIGHT 800
# define MOVE_STEP 0.1
# define ZOOM_FACTOR 1.2

# define JULIA_LEFT   97
# define JULIA_RIGHT  100
# define JULIA_UP     119
# define JULIA_DOWN   115 
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define EXIT 65307
# define ZOOM_IN_KEY 65451
# define ZOOM_OUT_KEY 65453
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define KEY_COLOR_SHIFT 99

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
}	t_fractal_type;

typedef struct s_app
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	double			zoom;
	double			offset_x;
	double			offset_y;
	int				color_shift;
	t_fractal_type	type;
	double			julia_re;
	double			julia_im;
}	t_app;

void	print_usage(void);
void	setup_hooks(t_app *app);
int		check_args(int argc, char **argv, t_app *app);
int		init_window(t_app *app);
double	ft_atof(const char *str);
int		ft_is_valid_float(const char *str);
int		mandelbrot(double x, double y);
int		burning_ship(double cx, double cy);
int		julia(double zx, double zy, double cx, double cy);
void	render_fractal(t_app *app);
void	put_pixel(t_app *app, int x, int y, int color);
int		get_color(int iter, int shift);

#endif