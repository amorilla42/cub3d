#include "cub3D.h"
 
int	main(int argc, char **argv)
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
		ft_putstr_fd("Error\n Wrong number of arguments\n", 2);
	return (0);
}
