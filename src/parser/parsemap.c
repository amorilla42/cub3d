#include "../../cub3d.h"

static int check_texture(char *archive)
{
	int fd;
	size_t	len;

	fd = open(archive, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Texture ", 2);
		ft_putstr_fd(archive, 2);
		ft_putendl_fd(" does not exist", 2);
		return (1);
	}
	close(fd);
	len = (int)ft_strlen(archive);
	if((len > 4) && (archive[len - 4] == '.')
		&& (archive[len - 3] == 'x')
		&& (archive[len - 2] == 'p')
		&& (archive[len - 1] == 'm'))
		return (0);
	ft_putstr_fd("Error: Texture ", 2);
	ft_putstr_fd(archive, 2);
	ft_putendl_fd(" invalid file extension", 2);
	return (1);
}

static int check_file(char *archive)
{
	int fd;
	size_t	len;

	fd = open(archive, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error: File does not exist", 2);
		return (1);
	}
	close(fd);
	len = (int)ft_strlen(archive);
	if((len > 4) && (archive[len - 4] == '.')
		&& (archive[len - 3] == 'c')
		&& (archive[len - 2] == 'u')
		&& (archive[len - 1] == 'b'))
		return (0);
	ft_putendl_fd("Error: Invalid file extension", 2);
	return (1);
}

static int	load_textures(char *archive, t_data *data)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open(archive, O_RDONLY);
	line = get_next_line(fd);
	while (line[0] != '1' && line[0] != '0')
	{
		if(line[0] != '\n')
		{
			if (line[0] == 'N' && line[1] == 'O')
				data->mapinfo->no_path = ft_substr(line, 3, ft_strlen(line)-4);
			if (line[0] == 'S' && line[1] == 'O')
				data->mapinfo->so_path = ft_substr(line, 3, ft_strlen(line)-4);
			if (line[0] == 'W' && line[1] == 'E')
				data->mapinfo->we_path = ft_substr(line, 3, ft_strlen(line)-4);
			if (line[0] == 'E' && line[1] == 'A')
				data->mapinfo->ea_path = ft_substr(line, 3, ft_strlen(line)-4);
			if (line[0] == 'F' && line[1] == ' ')
				data->mapinfo->floor_color_B = 3;
			if (line[0] == 'C' && line[1] == ' ')
				data->mapinfo->ceiling_color_B = 4;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (i != 6 || !data->mapinfo->no_path || !data->mapinfo->so_path
		|| !data->mapinfo->we_path || !data->mapinfo->ea_path)//añadir los colores en array????? es pregunta
		return (ft_putendl_fd("Error: Missing information", 2), 1);
	if (check_texture(data->mapinfo->no_path) || check_texture(data->mapinfo->so_path)
		|| check_texture(data->mapinfo->we_path) || check_texture(data->mapinfo->ea_path))
		return (1);
	return (0);
}

int	parsemap(char *archive, t_data *data)
{	
	if (check_file(archive) || load_textures(archive, data))
	{
		return (1);
	}

	printf("NO: %s\n", data->mapinfo->no_path);
	printf("SO: %s\n", data->mapinfo->so_path);
	printf("WE: %s\n", data->mapinfo->we_path);
	printf("EA: %s\n", data->mapinfo->ea_path);
	printf("F: %d\n", data->mapinfo->floor_color_B);
	printf("C: %d\n", data->mapinfo->ceiling_color_B);

	return (0);
}