

#include "../../cub3d.h"

int	enter_map(char *archive, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(archive, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error: File does not exist", 2);
		return (1);
	}
	line = get_next_line(fd);
	while (line[0] != '1' && line[0] != '0')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	data->map = ft_calloc(sizeof(char *) * (i + 1), 1);
	ft_printf("i = %d\n", i);
	close(fd);
	return (0);

}
