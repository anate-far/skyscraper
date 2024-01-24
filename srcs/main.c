#include <stdio.h>
#include <stdlib.h>
#include "ft.h"

int main(int argc, char** argv)
{
    if(argc < 2)
        return(EXIT_FAILURE);
    if(atoi(argv[1]) != atoi(argv[2]))
    {
        printf("ERROR : Impossible de generer une grille non carre\n");
        return(EXIT_FAILURE);
    }
    int* grid = ft_set_grid(atoi(argv[1]), atoi(argv[2]));
    int* setting_grid = ft_set_grid(atoi(argv[1]), 4);
    
    // for(int i = 0; i < 4; i++)
    // {
    //     //printf("%s\n", argv[i+3]);
    //     ft_set_setting_grid_value(setting_grid, argv[i+3], 4,i);
    // }
    //Test setting grid
    // tab 4 par 4
    //l1 = top / l2 = bot / l3 = left / l4 = right
        setting_grid[0] = 2; setting_grid[1] = 1; setting_grid[2] = 2; setting_grid[3] = 4;
        setting_grid[4] = 2; setting_grid[5] = 4; setting_grid[6] = 2; setting_grid[7] = 1;
        setting_grid[8] = 2; setting_grid[9] = 3; setting_grid[10] = 1; setting_grid[11] = 2;
        setting_grid[12] = 3; setting_grid[13] = 2; setting_grid[14] = 2; setting_grid[15] = 1;

    for(int i = 0; i < atoi(argv[1]) * 4; i++)
    {
        if(i % 4 == 0 && i > 0)
            printf("\n");
        printf("%d",setting_grid[i]);    
    }
    printf("\n\n");

   if(ft_generate_skyscraper(grid,setting_grid, 0) == 1)
        printf("Sa marche\n");
    
    //Fin du test

    ft_dislay_grid(grid);
    ft_destroy_grid(grid);

    return(EXIT_SUCCESS);
}

