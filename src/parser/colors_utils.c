#include "cub3d.h"

int	check_if_number(t_data *data, char *nbr)
{
	int	valid;
	int	i;

	i = -1;
	while (++i < ft_strlen(nbr))
	{
		if (!ft_isdigit(nbr[i]))
		{
			ft_putstr_fd(NOT_NUMBER_ERR, STDERR_FILENO);
			free_and_exit(data, EXIT_FAILURE);
		}
	}
	ft_atoi(nbr);
}

unsigned int	convert_to_hex(int r, int g, int b)
{
	unsigned int	rgb;

	rgb = (r << 16) | (g << 8) | b;
	return ((rgb << 8) | 0xff);
}
