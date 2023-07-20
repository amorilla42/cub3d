#include "cub3d.h"

static void init_graphic_env(t_data *data)
{

}

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (ft_putendl_fd(ARGS_ERR, STDERR_FILENO), EXIT_FAILURE);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO), EXIT_FAILURE);
	init_game_data(data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!(data->mlx))
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	init_graphic_env(data);
	mlx_key_hook(data->mlx, &key_func, data);
	mlx_loop(data->mlx);
	free_and_exit(data, EXIT_SUCCESS);
}


/*int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game = init_game(argv[1]);
		if (game.error)
			return (1);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.res.x, game.res.y, "cub3D");
		mlx_hook(game.win, 2, 1L << 0, key_press, &game);
		mlx_hook(game.win, 3, 1L << 1, key_release, &game);
		mlx_hook(game.win, 17, 1L << 17, close_window, &game);
		mlx_loop_hook(game.mlx, update, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
	return (0);
}*/

