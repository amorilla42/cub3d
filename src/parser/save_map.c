

#include "../../cub3d.h"

int	load_file(char *file, t_data *data)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(data->fd, &tmp, 1) > 0)
	{
		if (tmp == '\n')
			i++;
	}
	close(data->fd);
	data->in_cnt = malloc(sizeof(char *) * (i + 1));
	if (!data-->in_cnt)
		ft_errexit(data-, "Error\nNot enough memory available");
	data->fd = open(data->in_route, O_RDONLY);
	while (j < i)
	{
		init->in_cnt[j] = get_next_line(init->in_fd);
		j++;
	}
	init->in_cnt[j] = NULL;
	close(init->in_fd);
	map_parser(init);
	get_colors(init);
}
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
	line = get_next_line(fd); //WTF PORQUE LEE UN 100 AL PRINCIPIO DEL ARCHIVO????????????????????
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
	printf("i = %d\n", i);
	close(fd);
	return (0);

}
