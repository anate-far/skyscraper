#include <stdio.h>
#include <stdlib.h>
#include "ft.h"

int* ft_set_grid(int lenght, int width)
{
    int total_size = lenght * width;
    int* grid = malloc(sizeof(int) * total_size);

    for(int i = 0; i < total_size; i++)
    {
        grid[i] = 0;
    }
    grid[total_size] = -1;
    
    return(grid);
}

int ft_calc_size_tab(int* tab)
{
    int i = 0;
    while (tab[i] != -1)
        i++;
    return(i);
}

int ft_calc_collone_with_index(int* grid, int index)
{
    for(int i = 1; i < ft_sqrt(ft_calc_size_tab(grid)); i++)
    {
        if((index + i) % ft_sqrt(ft_calc_size_tab(grid)) == 0)
        {
            return(ft_sqrt(ft_calc_size_tab(grid)) - i);
        }
    }
    return(0);
}

void ft_dislay_grid(int* grid)
{
    int total_size_grid = ft_calc_size_tab(grid);
    int lenght_grid = ft_sqrt(total_size_grid);
    
    for(int i = 0; i < total_size_grid; i++)
    {
        if(i % lenght_grid == 0 && i > 0)
            printf("\n\n");
        printf("%d | ", grid[i]);
    }
    printf("\n");
}

void ft_destroy_grid(int * grid)
{
    free(grid);
}

int* ft_set_setting_grid_value(int* setting_grid, char* value, int size_line, int nb_line)
{
    for(int i = 0;i < size_line; i++)
    {
        int int_value = ft_segment_value(value, i);
        setting_grid[nb_line + i] = int_value;
    }
    return setting_grid;
}