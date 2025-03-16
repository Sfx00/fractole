#ifndef FRACTOLE_H
#define FRACTOLE_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./minilibx-linux/mlx.h"


#define width 800
#define height 800


typedef struct s_complex
{
    double  r;
    double  i;
}t_complex;


typedef struct s_toys
{
    //setup mlx
    void *connection;
    void *window;
    void *img_ptr;
    
    // image info :
    char *img;
    int bits_per_pixel;
    int size_line;
    int endian;
    
    //fractol info :
    char *type;
    double  r;
    double  i;
    int     iteration;
    double  zoom;

    // hooks tools
    double shift_x;
    double shift_y;

    int coloring;

}t_toys;

void    fractol(t_toys *box);
int     handle_input(char **av, int ac, t_toys *box);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
size_t  ft_strlen(const char *str);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *check_name(char *name);
double  ft_atod(char *str);
void	show_help(void);
void    print_error(char *msg);
void    cleaner(t_toys *box);
int     key_handler(int keycode, t_toys *box);
int     mouse_handler(int button, int x, int y, void *param);
int     close_window(void *param);
int     mandelbrot(t_toys *box);
int     julia(t_toys *box);
void    convert_complex(t_complex *c, int x, int y, t_toys *box);
int     check_diverge(t_complex *c);
void    set_pixel_color(int iteration, int x, int y, t_toys *box);

#endif