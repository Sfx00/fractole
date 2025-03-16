#include "fractole.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
    {
        if (s1[i] == s2[i])
        {
            i++;
        }
        else
            break;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t  ft_strlen(const char *str)
{
    size_t len;

    len = 0;
    if(!str)
        return(0);
        
    while(str[len])
        len++;
    return(len);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *p;

    i = 0;
    p = (char *)malloc(sizeof(char) * len + 1);
    if(!p)
    {
        return NULL;
    }
    if(start >= ft_strlen(s) || len == 0)
    {
        return NULL;
    }

   while (s[start + i] != '\0' && i < len)
   {
        p[i] = s[start + i];
        i++;
   }
   p[i] = '\0';
   return (p);
}

int ft_atoi(const char *nptr)
{
    size_t r;
    int i;
    int d;
    char * npt;

    r = 0;
    i = 0;
    d = 0;
    npt = (char *) nptr;
    while (npt[i] == ' ' || (npt[i] >= '\t' && npt[i] <= '\r'))
        i++;
    if(npt[i] == '-' || npt[i] == '+')
    {
        if (npt[i] == '-')
            d = 1;
        i++;
    }
    while (npt[i] >= '0' && npt[i] <= '9')
    {
        r = r * 10 + (npt[i] - '0');
        i++;
    }
    if (d == 1)
        return (-r);
    return (r);
}

double ft_atod(char *str)
{
    int     sign;
    double  n[2];

    n[0] = 0;
    n[1] = 0.1;
    sign = 1;
    if(!str)
        return(0);
    if(*str == '-' || *str == '+')
    {
        if(*str == '-')
            sign = -1;
        str++;
    }
    while((*str >= '0' && *str <= '9') && *str)
        n[0] = n[0] * 10 + (*str++ - '0');
    if(*str == ',' || *str == '.')
    {
        while((*++str >= '0' && *str <= '9') && *str)
        {
            n[0] = n[0] + (*str - '0') * n[1];
            n[1]*= 0.1;
        }  
    }
    return(n[0] * sign);
}
