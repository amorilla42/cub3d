#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		error;

	if (argc == 2)
	{
		error = parsemap(argv[1], &data);
		if (error == 1)
		{
			ft_putstr_fd("Error\ninvalid map???? en verda renta poner distintos errores pa cada fallo????\n", 2);
			return (1);
		}
		
		ft_putstr_fd("perfectisimo\n", 1);
	}
	else
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);

	
	return (0);
}
