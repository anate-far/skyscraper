#include <stdlib.h>
#include "ft.h"

int ft_sqrt(int value)
{
    int i = 10000000;
    int min = 0;
    int max = value;
    int mid;

    if(value < 0)
        return(0);
    if(value == 1)
        return(1);
    if(value > 46341)
        max = 46341;
    mid = (min + max) / 2;
    while(i > 0)
    {
        if(value == mid * mid)
            return(mid);
        if( mid * mid > value)
            max = mid;
        else min = mid;
        if(min + 1 == max)
            return(0);
        mid = (min + max) / 2;
        i++;
    }
    return (0);
}

int* ft_copy_tab_int(int* tab_a, int* tab_b)
{
    int size_a = ft_calc_size_tab(tab_a);

    for(int i = 0; i < size_a; i++)
    {
        tab_b[i] = tab_a[i];
    }

    return tab_b;
}



int ft_segment_value(char* char_nb, int order_value)
{
    int nb = atoi(char_nb);
    int r;

    int revese_nb = 0;
    for(int i = 0; i <= order_value; i++)
    {
    //reverse
        revese_nb *= 10;
        revese_nb += nb % 10;
        nb /= 10;
    //search good value
        int q = revese_nb / 10;
        r = revese_nb % 10;
        revese_nb = q;
    }
    return(r);
}