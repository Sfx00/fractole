#include "fractole.h"

int close_window(void *param)
{
    t_toys *box;

    box = (t_toys *)param;
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
    exit(1);
}

int mouse_handler(int button, int x, int y, void *param)
{
    t_toys *box;
    x *= 1;
    y *= 1;
    box = (t_toys *)param;

    if(button == 4)
        box->zoom *= 1.2;
    else if(button == 5)
        box->zoom /= 1.2;
    fractol(box);
    return(0);
}



int key_handler(int keycode, t_toys *box)
{
    if(keycode == 65307)
    {
        cleaner(box);
        exit(1);
    }
    else if(keycode == 65363)
        box->shift_x -= 0.5;
    else if(keycode == 65361)
        box->shift_x += 0.5;
    else if(keycode == 65364)
        box->shift_y += 0.5;
    else if(keycode == 65362)
        box->shift_y -= 0.5;
    else if(keycode == 65451)
        box->iteration += 10;
    else if(keycode == 65453)
        box->iteration -= 10;
    else if (keycode == 32)
        box->coloring += 1;
    fractol(box);
    return (0);
}
