#include "fractole.h"

int check_comma(char *arg)
{
    int i;
    int dot, comma;

    i = 0;
    dot = 0;
    comma = 0;
    if(arg[i] == '\0')
        return(0);
    if(arg[i] == '.' || arg[i] == ',')
        return(0);
    while(arg[i])
    {
        if(arg[i] == '.')
            dot++;   
        if (arg[i] == ',')
            comma++;
        i++;
    }
    if(arg[i - 1] == ',' || arg[i - 1] == '.')
        return(0);
    if((dot == 1 && comma == 0) || (dot == 0 && comma == 1))
        return(1);
    if(dot == 0 && comma == 0)
        return (1);
    return(0);
}
int check_number(char *arg)
{
    int i;

    i = 0;
    if(!arg[i])
        return(0);
    if(arg[i] == '-' || arg[i] == '+')
        i++;
    while(arg[i])
    {
        if(arg[i] >= '0' && arg[i] <= '9')
            i++;
        else if(arg[i] == ',' || arg[i] == '.')
            i++;
        else
            return(0);
    }
    return(1);
}
char *check_name(char *str)
{
    char    *name;
    int i;
    size_t  last;

    if(!*str)
        return(NULL);
    i = 0;
    last = ft_strlen(str);
    last -= 1;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[last] == ' ' || str[last] == '\t')
        last--;
    name = ft_substr(str + i, 0, (last - i) + 1);
    if(!name)
        return(NULL);
    return(name);
}
double handle_parameter(char *arg)
{
    int i;
    int last;
    char *param;
    double  num;
    i = 0;
    last = ft_strlen(arg);
    while(arg[i] == ' ' || arg[i] == '\t')
        i++;
    while (arg[last - 1] == ' ' || arg[last - 1] == '\t')
        last--;
    param = ft_substr(arg + i, 0, (last - i));
    if(!param)
        return (0);
    if(!check_comma(param) || !check_number(param))
    {
        free(param);
        return(0);
    }
    num = ft_atod(param);
    free(param);
    return(num);
}

int handle_input(char **av, int ac, t_toys *box)
{
    char *name;

    name = check_name(av[1]);
    if (!name)
        return(0);
    if(!ft_strncmp(name,"mandelbrot",ft_strlen(av[1])) && ac == 2)
    {
        box->type= name;
        return(1);
    }
    else if(!ft_strncmp(name,"julia",ft_strlen(av[1])) && ac == 4)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    {
        box->type = name;
        box->r = handle_parameter(av[2]);
        box->i = handle_parameter(av[3]);
        if(box->r && box->i)
            return(1);
    }
    free(name);
    return (0);                                                                                                                                                                                                                                                                                                                                                                                                                                   
}
