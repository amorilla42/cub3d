

#include "../../cub3d.h"

void	load_file(char *file, t_data *data)
{
	int		i;
	int		j;
	char	aux;
	
	j = 0;
	i = 0;
	while (read(data->fd, &aux, 1) > 0)
	{
		if (aux == '\n')
			i++;
	}
	close(data->fd);
	data->file = malloc(sizeof(char *) * (i + 1));
	if (!data->file)
		print_err_exit(data, "Error\nNot enough memory available");
	data->fd = open(file, O_RDONLY);
	while (j < i)
	{
		data->file[j] = get_next_line(data->fd);
		j++;
	}
	data->file[j] = NULL;
	close(data->fd);
	/*

	map_parser(init);	//TODO
	get_colors(init);	//TODO
	
	*/
}







void	enter_map(char *archive, t_data *data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (data->fd == -1)
		print_err_exit(data, "Error:\nMap file does not exist");
	line = data->file[i];
	while (line[0] != '1' && line[0] != '0')
	{
		free(line);
		i++;
		line = data->file[i];
	}
	while (line)
	{
		j++;
		i++;
		free(line);
		line = data->file[i];
	}
	data->map = ft_calloc(sizeof(char *) * (j + 1), 1);
	if (!data->map)
		print_err_exit(data, "Error\nNot enough memory available");

}
