#include "cub3d.h"

void    free_and_exit(t_data *data, int exit_code_number)
{
    if (data->mlx)
    {
        mlx_close_window(data->mlx);
        mlx_terminate(data->mlx);
    }
    free(data);
    exit(exit_code_number);
}