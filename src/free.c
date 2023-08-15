#include "../cub3d.h"

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

void	print_err_exit(t_data *data, char *str)
{
	struct_free_ft(init);
	ft_putstr_fd(str, 2);
	exit(1);
}