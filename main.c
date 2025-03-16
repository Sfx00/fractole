#include "fractole.h"

int init(t_toys *box)
{
    box->connection = mlx_init();
    if(!box->connection)
    {
        free(box->type);
        return(0);
    }
    box->window = mlx_new_window(box->connection,width,height,"Fractol");
    if(!box->window)
    {
        cleaner(box);
        return(0);
    }
    box->img_ptr = mlx_new_image(box->connection,width,height);
    if(!box->img_ptr)
    {
        cleaner(box);
        return(0);
    }
    box->img = mlx_get_data_addr(box->img_ptr,&box->bits_per_pixel,&box->size_line,&box->endian);
    if(!box->img)
    {
        cleaner(box);
        return(0);
    }
    return(1);
}

void fractol(t_toys *box)
{
    if(!ft_strncmp(box->type,"mandelbrot",ft_strlen(box->type)))
        mandelbrot(box);
    else
        julia(box);
}

int main(int ac, char *av[])
{
    t_toys box;
    
    if(ac < 2 || !handle_input(av,ac,&box))
    {
        show_help();
        print_error("\nError: Invalid input! Please check the usage.\n");
    }
	if(!init(&box))
        print_error("Error!");
    box.shift_x = 0.0;
    box.shift_y = 0.0;
    box.iteration = 42;
    box.zoom = 1.0;
    box.coloring = 1;
    mlx_mouse_hook(box.window,mouse_handler,&box);
    mlx_key_hook(box.window,key_handler,&box);
    mlx_hook(box.window, 17,0,close_window,&box);
    mlx_loop(box.connection);
}
