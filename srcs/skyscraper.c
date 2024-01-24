#include <stdlib.h>
#include <stdio.h>
#include "ft.h"

/*
    je met une premiere valeur
        si c bon je passe a la suivante
        sinon j'increment de 1

        si aucune valeur n'est bonne je repasse a la case precedente
        j'incrmentde de 1 et je recomence
*/

int ft_generate_skyscraper(int* grid, int* setting_grid, int index)
{
    if(index >= ft_calc_size_tab(grid))
        return(1);
    int i;
    for(i = 0; i < ft_sqrt(ft_calc_size_tab(grid)); i++)
    {
        if(ft_check_grid_error(grid, setting_grid, index, i+1) == 1)
        {
            grid[index] = i + 1;
            if(ft_generate_skyscraper(grid, setting_grid, index+1) == 1)
            {
                return(1);
            }
        }
    }
    grid[index] = 0;
    return(0);
}