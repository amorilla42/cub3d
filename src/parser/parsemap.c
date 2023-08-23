#include "cub3d.h"

static void check_texture(char *archive, t_data *data)
{
	int fd;
	size_t	len;

	fd = open(archive, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	close(fd);
	len = (int)ft_strlen(archive);
	if(!((len > 4) && (archive[len - 4] == '.')
		&& (archive[len - 3] == 'p')
		&& (archive[len - 2] == 'n')
		&& (archive[len - 1] == 'g')))
	{
		ft_putstr_fd(EXTENSION_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

static void check_file(t_data *data, char *archive)
{
	int		fd;
	size_t	len;

	fd = open(archive, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd(FILE_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	close(fd);
	len = (int) ft_strlen(archive);
	if (!((len > 4) && (archive[len - 4] == '.')
		&& (archive[len - 3] == 'c')
		&& (archive[len - 2] == 'u')
		&& (archive[len - 1] == 'b')))
	{
		ft_putendl_fd(EXTENSION_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

static int	count_useful_lines(char *line, t_data *data)
{
	if(line[0] != '\n')
	{
		if (line[0] == 'N' && line[1] == 'O')
			data->map_info->no_path = ft_substr(line, 3, ft_strlen(line)-4);
		if (line[0] == 'S' && line[1] == 'O')
			data->map_info->so_path = ft_substr(line, 3, ft_strlen(line)-4);
		if (line[0] == 'W' && line[1] == 'E')
			data->map_info->we_path = ft_substr(line, 3, ft_strlen(line)-4);
		if (line[0] == 'E' && line[1] == 'A')
			data->map_info->ea_path = ft_substr(line, 3, ft_strlen(line)-4);
		/*
		if (line[0] == 'F' && line[1] == ' ')
			data->mapinfo->floor_color_b = 3; //falta añdir los colores bien (parsecolor o algo asi) hexadecimal????
		if (line[0] == 'C' && line[1] == ' ')
			data->mapinfo->ceiling_color_b = 4; //falta añdir los colores bien
		*/
		return (1);
	}
	return (0);
}

static void	load_textures(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = data->file[j];
	while (line && line[0] != '1' && line[0] != '0')
	{
		i += count_useful_lines(line, data);
		line = data->file[++j];
	}
	if (i != 6 || !data->map_info->no_path || !data->map_info->so_path
		|| !data->map_info->we_path || !data->map_info->ea_path) //añadir los colores en array????? es pregunta
	{
		ft_putstr_fd(INFO_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	check_texture(data->map_info->no_path, data);
	check_texture(data->map_info->so_path, data);
	check_texture(data->map_info->we_path, data);
	check_texture(data->map_info->ea_path, data);
}

void	parsemap(char *archive, t_data *data)
{
	data->fd = open(archive, O_RDONLY);
	load_file(archive, data);
	check_file(data, archive);
	load_textures(data);
	enter_map(data);
}
