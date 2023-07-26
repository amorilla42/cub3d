#include "cub3d.h"

void	press_key(mlx_key_data_t keydata, void	*game_data)
{
	t_data	*data;

	(void) keydata;
	data = game_data;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		free_and_exit(data, EXIT_SUCCESS);
} 

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_putendl_fd(ARGS_ERR, STDERR_FILENO), EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO), EXIT_FAILURE);
	//init_game_data(data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!(data->mlx))
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	//init_graphic_env(data);
	mlx_key_hook(data->mlx, &press_key, data);
	mlx_loop(data->mlx);
	free_and_exit(data, EXIT_SUCCESS);
}
