#include "fractole.h"


int iterate_complex(t_complex *z, t_complex *c, t_toys *box)
{
    int i;
    double tmp;
    
    i = 0;
    z->r = 0.0;
    z->i = 0.0;

    while(i < box->iteration)
    {
        tmp = (z->r * z->r) - (z->i * z->i);
        z->i = 2 * z->r * z->i;
        z->r = tmp;
        z->r += c->r;
        z->i += c->i;
        if(check_diverge(z))
            return(i + 1);
        i++;
    }
    return(box->iteration);
}

int mandelbrot(t_toys *box)
{
    t_complex c;
    t_complex z;

    int x;
    int y;
    int iteration;

    y = 0;

    while(y < height)
    {
        x = 0;
        while(x < width)
        {
            convert_complex(&c,x,y,box);
            iteration = iterate_complex(&z,&c,box);
            set_pixel_color(iteration,x,y,box);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(box->connection,box->window,box->img_ptr,0,0);
    return(0);
}
