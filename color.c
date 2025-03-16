#include "fractole.h"

void set_pixel_color(int iteration, int x, int y, t_toys *box)
{
    int pos;
    int color;
    int r;
    int g;
    int b;
    
    if (iteration == box->iteration)
        color = 0x000000;
    else
    {
        r = box->coloring * (iteration * 5) % 256;
        g = box->coloring * (iteration * 3) % 256;  
        b = box->coloring * (255 - ((iteration * 10) % 256)) ;
        color = (r << 16) | (g << 8) | b;
    }
    pos = (y * box->size_line) + (x * (box->bits_per_pixel / 8));
    *(unsigned int *)(box->img + pos) = color;
}
