#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_putendl_fd(ARGS_ERR, STDERR_FILENO), EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO), EXIT_FAILURE);
	data->map_info = ft_calloc(1, sizeof(t_map_info));
	if (!data->map_info)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO), free(data), EXIT_FAILURE);
	parsemap(argv[1], data);
	init_textures(data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!(data->mlx))
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	init_images(data);
	print_ceiling_floor(data);
	mlx_loop_hook(data->mlx, &move_player, data);
	mlx_loop(data->mlx);
	free_and_exit(data, EXIT_SUCCESS);
}
