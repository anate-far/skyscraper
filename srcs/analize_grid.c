#include <stdlib.h>
#include <stdio.h>
#include "ft.h"

/*
    on regarde si la valeur correspond
        -au parametre de la ligne  : ok
        -au parametre de la colomne : ok
        -qu elle n'est pas 2 fois sur la ligne ou la colomne
*/

int ft_check_line_setting(int* grid, int* setting_grid, int index, int value)
{
    int nb_line = index / ft_sqrt(ft_calc_size_tab(grid)); // on cherche la ligne qui correspond a l'index
    int current_read_value =  nb_line * ft_sqrt(ft_calc_size_tab(grid)); // on place le curseur de lecteur au debut de cette ligne
    int view_value_left = setting_grid[ft_sqrt(ft_calc_size_tab(setting_grid)) * 2 + nb_line]; //On cherche la ligne des parametre de de gauche et on se place sur la bonne ligne
    int view_value_right = setting_grid[ft_sqrt(ft_calc_size_tab(setting_grid)) * 3 + nb_line]; //On cherche la ligne des parametre de de droite et on se place sur la bonne ligne
    int current_view_value_left = 1;
    int current_view_value_right = 1;
    int i = 0;
    int* grid_copy = ft_set_grid(ft_sqrt(ft_calc_size_tab(grid)), ft_sqrt(ft_calc_size_tab(grid)));

    grid_copy = ft_copy_tab_int(grid, grid_copy);
    grid_copy[index] = value;
    int tmp = grid_copy[current_read_value]; 
    // printf("LIGNE\n");
    // ft_dislay_grid(grid_copy);
    // printf("\n\n");
    //left
    while(i < ft_sqrt(ft_calc_size_tab(grid)))
    {
        if(grid_copy[current_read_value + i] > tmp )
        {
            current_view_value_left++;
            tmp = grid_copy[current_read_value + i];
        }
        if(grid_copy[current_read_value + i] == 0)
        {
            if(current_view_value_left <= view_value_left)
            {
                free(grid_copy);
                return(1);
            }
            else
            {
                free(grid_copy);
                return(0);
            }
        }
        i++;
    }
    if(current_view_value_left != view_value_left)
    {
        free(grid_copy);
        return(0);
    }
    //right
    i--;
    tmp = grid_copy[current_read_value + i];
    while(i >= 0)
    {
        if(grid_copy[current_read_value + i] > tmp )
        {
            current_view_value_right++;
            tmp = grid_copy[current_read_value + i];
        }
        i--;
    }
        if(current_view_value_right != view_value_right)
        {
            free(grid_copy);
            return(0);
        }
    free(grid_copy);
    return(1);

}

int ft_check_column_setting(int* grid, int* setting_grid, int index,int value)
{
    int lenght_size_grid = ft_sqrt(ft_calc_size_tab(grid));
    int nb_column = ft_calc_collone_with_index(grid, index); // on cherche la colone qui correspond a l'index
    int current_read_value =  nb_column; // on place le curseur de lecteur au debut de cette colone
    int view_value_top = setting_grid[ft_sqrt(ft_calc_size_tab(setting_grid)) * 0 + nb_column]; //On cherche la ligne des parametre de de gauche et on se place sur la bonne ligne
    int view_value_bot = setting_grid[ft_sqrt(ft_calc_size_tab(setting_grid)) * 1 + nb_column]; //On cherche la ligne des parametre de de droite et on se place sur la bonne ligne
    int current_view_value_top = 1;
    int current_view_value_bot = 1;
    int* grid_copy = ft_set_grid(lenght_size_grid, lenght_size_grid);

    grid_copy = ft_copy_tab_int(grid, grid_copy);
    grid_copy[index] = value;
    int tmp = grid_copy[current_read_value];
    // printf("COLONE\n");
    // ft_dislay_grid(grid_copy);
    // printf("\n\n");
    int i = 0;
    //top
    while(i < ft_sqrt(ft_calc_size_tab(grid)))
    {
        if(grid_copy[current_read_value + (i * lenght_size_grid )] > tmp )
        {
            current_view_value_top++;
            tmp = grid_copy[current_read_value + (i * lenght_size_grid )];
        }
        if(grid_copy[current_read_value + (i * lenght_size_grid )] == 0)
        {
            if(current_view_value_top <= view_value_top)
            {
                free(grid_copy);
                return(1);
            }
            else
            {
                free(grid_copy);
                return(0);
            }
        }
        i++;
    }
    if(current_view_value_top != view_value_top)
    {
        return(0);
    }
    //bot
    i--;
    tmp = grid_copy[current_read_value + (i * lenght_size_grid )];
    while(i >= 0)
    {
        if(grid_copy[current_read_value + (i * lenght_size_grid )] > tmp )
        {
            current_view_value_bot++;
            tmp = grid_copy[current_read_value + (i * lenght_size_grid )];
        }
        i--;
    }
        if(current_view_value_bot != view_value_bot)
        {
            return(0);
        }
    free(grid_copy);
    return(1);
}

int ft_check_no_pair(int* grid, int index, int value)
{
    int lenght_grid = ft_sqrt(ft_calc_size_tab(grid));
    int nb_line = index / lenght_grid;
    int start_line = nb_line * lenght_grid;
    int nb_column = ft_calc_collone_with_index(grid, index);
    int* grid_copy = ft_set_grid(ft_sqrt(ft_calc_size_tab(grid)), ft_sqrt(ft_calc_size_tab(grid)));

    grid_copy = ft_copy_tab_int(grid, grid_copy);
    grid_copy[index] = value;
    // printf("PAIR\n");
    // ft_dislay_grid(grid_copy);
    // printf("\n\n");
    //line
    for(int i = 0; i < lenght_grid; i++)
    {
        if(grid_copy[start_line + i ] != 0)
        {
            for(int y = 0; y < lenght_grid; y++)
            {
                if(i != y)
                {
                    if(grid_copy[start_line + i] == grid_copy[start_line + y])
                    {
                        free(grid_copy);
                        return(0);
                    }
                }
            }
        }
    }
    //columne
    for(int i = 0; i < lenght_grid; i++)
    {
        if(grid_copy[nb_column + (i * lenght_grid)] != 0)
        {
            for(int y = 0; y < lenght_grid; y++)
            {
                if(i != y)
                {
                    if(grid_copy[nb_column + (i * lenght_grid)] == grid_copy[nb_column + (y * lenght_grid)])
                    {
                        free(grid_copy);
                        return(0);
                    }
                }
            }
        }
    }
    free(grid_copy);
    return(1);
}

int ft_check_grid_error(int* grid,int* setting_grid, int index, int value)
{
    if(ft_check_no_pair(grid, index, value) == 0)
    {
        //printf("Error : 2 valeur identique\n");
        return(0);
    }
    else if(ft_check_line_setting(grid,setting_grid, index,value) == 0)
    {
       // printf("Error : Ligne invalide \n");
        return(0);
    }
    else if(ft_check_column_setting(grid, setting_grid, index, value) == 0)
    {
        //printf("Error : Colone invalide\n");
        return(0);
    }
    return(1);
}