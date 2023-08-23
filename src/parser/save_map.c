#include "cub3d.h"

void	load_file(char *file, t_data *data)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	while (read(data->fd, &aux, 1) > 0)
	{
		if (aux == '\n')
			i++;
	}
	close(data->fd);
	data->file = ft_calloc(sizeof(char *), i + 1);
	if (!data->file)
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	data->fd = open(file, O_RDONLY);
	j = 0;
	while (j < i)
	{
		data->file[j] = get_next_line(data->fd);
		j++;
	}
	close(data->fd);
	/*

	map_parser(init);	//TODO
	get_colors(init);	//TODO
	
	*/
}

void	enter_map(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->fd == -1)
	{
		ft_putendl_fd(FILE_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	line = data->file[i];
	while (line[0] != '1' && line[0] != '0')
	{
		i++;
		line = data->file[i];
	}
	while (line)
	{
		j++;
		i++;
		line = data->file[i];
	}
	data->map = ft_calloc(sizeof(char *), j + 1);
	if (!data->map)
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}

}
