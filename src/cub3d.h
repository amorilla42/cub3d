#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"


// WINDOW SIZE
# define WIDTH 640
# define HEIGHT 480

typedef struct  s_data
{
    mlx_t   *mlx;

} t_data;

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

# define ARGS_ERR "Error\nWrong number of arguments"
# define MALLOC_ERR "Error\nMemory was not allocated"

void	press_key(mlx_key_data_t keydata, void	*game_data);
void    free_and_exit(t_data *data, int exit_code_number);











# endif