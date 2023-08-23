#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void) argc;
	(void) argv;
	/*if (argc != 2)
		return (ft_putendl_fd(ARGS_ERR, STDERR_FILENO), EXIT_FAILURE);*/
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO), EXIT_FAILURE);
	data->map_info = ft_calloc(1, sizeof(t_map_info));
	/*if (parsemap(argv[1], data))
	{
		ft_putstr_fd(INVALID_MAP, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}*/
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!(data->mlx))
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	init_data(data);
	print_ceiling_floor(data);
	mlx_loop_hook(data->mlx, &move_player, data);
	mlx_loop(data->mlx);
	free_and_exit(data, EXIT_SUCCESS);
}
