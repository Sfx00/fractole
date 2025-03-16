#include "fractole.h"

void convert_complex(t_complex *c, int x, int y, t_toys *box)
{
    double scale_factor;

    if(width > height)
        scale_factor = 4.0 / height;
    else
        scale_factor = 4.0 / width;

    c->r = (x - width / 2.0) * scale_factor * box->zoom + box->shift_x;
    c->i = (height / 2.0 - y) * scale_factor * box->zoom + box->shift_y;
}

int check_diverge(t_complex *c)
{
    double value;
    value = (c->r * c->r) + (c->i * c->i);
    if(value <= 4.0)
        return(0);
    else
        return(1);
}