#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data		data;
	int			error;

	data.mapinfo = ft_calloc(1, sizeof(t_mapinfo));
	if (argc == 2)
	{
		error = parsemap(argv[1], &data);
		/*
		if (error == 1)
		{
			ft_putstr_fd("Error\ninvalid map???? en verda renta poner distintos errores pa cada fallo????\n", 2);
			return (1);
		}
		*/
	}
	else
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);

	
	return (0);
}
