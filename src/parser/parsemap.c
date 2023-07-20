#include "../../cub3d.h"

static int	check_file_extension(char *archive)
{
	size_t	len;

	len = (int)ft_strlen(archive);
	return ((len > 4) && (archive[len - 4] == '.')
		&& (archive[len - 3] == 'c')
		&& (archive[len - 2] == 'u')
		&& (archive[len - 1] == 'b'));
}

int	parsemap(char *archive, t_data *data)
{
	(void)data;
	
	if (!check_file_extension(archive))
	{
		printf("Error\nInvalid file extension\n");
		return (1);
	}


	return (0);
}