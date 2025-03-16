#include "fractole.h"

void	show_help(void)
{
	write(1, "=====================================\n", 38);
	write(1, "       Fractol - Help Menu\n", 27);
	write(1, "=====================================\n\n", 39);

	write(1, "Usage: ./fractol [fractal] [options]\n\n", 38);

	write(1, "Available Fractals:\n", 20);
	write(1, "  mandelbrot      - Classic Mandelbrot Set\n", 43);
	write(1, "  julia          - Julia Set (Requires 2 parameters)\n\n\n", 54);

	write(1, "Options for Julia:\n", 20);
	write(1, "  ./fractol julia <real> <imaginary>\n", 37);
	write(1, "  Example: ./fractol julia -0.8 0.156\n\n", 39);

	write(1, "Controls:\n", 10);
	write(1, "  Arrows\t\t- Move view\n", 23);
	write(1, "  Scroll\t\t- Zoom in/out\n", 24);
	write(1, "  Space\t\t\t- Change color scheme\n", 32);
	write(1, "  ESC\t\t\t- Exit program\n\n\n", 24);

	write(1, "Example Usage:\n", 15);
	write(1, "  ./fractol mandelbrot\n", 24);
	write(1, "  ./fractol julia 0.285 0.01\n", 29);
}

void cleaner(t_toys *box)
{
	if(box->img_ptr)
		mlx_destroy_image(box->connection,box->img_ptr);
	if(box->window)
		mlx_destroy_window(box->connection,box->window);
	if(box->connection)
	{
		mlx_destroy_display(box->connection);
		free(box->connection);
	}
	if(box->type)
		free(box->type);
}


void print_error(char *msg)
{
    write(1,msg, ft_strlen(msg));
    write(1,"\n", 1);
    exit(1);
}
