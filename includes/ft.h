#ifndef FT_H
#define FT_H

//grid.c
int* ft_set_grid(int lenght, int width);
int ft_calc_size_tab(int* tab);
int ft_calc_collone_with_index(int* grid, int index);
void ft_dislay_grid(int* grid);
void ft_destroy_grid(int * grid);
int* ft_set_setting_grid_value(int* setting_grid, char* value, int size_line, int nb_line);

//tools.c
int ft_sqrt(int value);
int* ft_copy_tab_int(int* tab_a, int* tab_b);
int ft_segment_value(char* char_nb, int order_value);

//analize_grid.c
int ft_check_line_setting(int* grid, int* setting_grid, int index, int value);
int ft_check_column_setting(int* grid, int* setting_grid, int index, int value);
int ft_check_no_pair(int* grid, int index, int value);
int ft_check_grid_error(int* grid,int* setting_grid, int index, int value);

//skyscraper.c
int ft_generate_skyscraper(int* grid, int* setting_grid, int index);
#endif