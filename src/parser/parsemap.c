#include "cub3d.h"

static int check_texture(char *archive, t_data *data)
{
	int fd;
	size_t	len;

	fd = open(archive, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error:\nTexture ", 2);
		ft_putstr_fd(archive, 2);
		print_err_exit(data, " does not exist");
		return (1);// es posible quitarlo????
	}
	close(fd);
	len = (int)ft_strlen(archive);
	if((len > 4) && (archive[len - 4] == '.')
		&& (archive[len - 3] == 'p')
		&& (archive[len - 2] == 'n')
		&& (archive[len - 1] == 'g'))
		return (0);// este renta que esté
	ft_putstr_fd("Error:\nTexture ", 2);
	ft_putstr_fd(archive, 2);
	print_err_exit(data, " invalid file extension");
	return (1);// es posible quitarlo????
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

static int	count_useful_lines(char *line, t_data *data)
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
			data->mapinfo->floor_color_b = 3; //falta añdir los colores bien (parsecolor o algo asi) hexadecimal????
		if (line[0] == 'C' && line[1] == ' ')
			data->mapinfo->ceiling_color_b = 4; //falta añdir los colores bien
		return (1);
	}
	return (0);
}

static int	load_textures(char *archive, t_data *data)
{
	char *line;
	int i;
	int j;

	i = 0;
	j = 0;
	line = data->file[j];
	while (line && line[0] != '1' && line[0] != '0')
	{
		i += count_useful_lines(line, data);
		free(line);
		j++;
		line = data->file[j];
	}
	free(line);
	if (i != 6 || !data->mapinfo->no_path || !data->mapinfo->so_path
		|| !data->mapinfo->we_path || !data->mapinfo->ea_path)//añadir los colores en array????? es pregunta
		print_err_exit(data, "Error:\nMissing or too much information");
	if (check_texture(data->mapinfo->no_path, data)
		|| check_texture(data->mapinfo->so_path, data)
		|| check_texture(data->mapinfo->we_path, data)
		|| check_texture(data->mapinfo->ea_path, data))
		return (1);
	return (0);
}

int	parsemap(char *archive, t_data *data)
{
	data->fd = open(archive, O_RDONLY);
	load_file(archive, data);






	if (check_file(archive) || load_textures(archive, data))
	{
		return (1);
	}
	enter_map(archive, data);

	printf("NO: %s\n", data->mapinfo->no_path);
	printf("SO: %s\n", data->mapinfo->so_path);
	printf("WE: %s\n", data->mapinfo->we_path);
	printf("EA: %s\n", data->mapinfo->ea_path);
	printf("F: %d\n", data->mapinfo->floor_color_b);
	printf("C: %d\n", data->mapinfo->ceiling_color_b);

	return (0);
}