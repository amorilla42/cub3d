#include "../../cub3d.h"

static int	check_file_extension(char *archive)
{
	size_t	len;

	len = (int)ft_strlen(archive);
	if((len > 4) && (archive[len - 4] == '.')
		&& (archive[len - 3] == 'c')
		&& (archive[len - 2] == 'u')
		&& (archive[len - 1] == 'b'))
		return (0);
	ft_putendl_fd("Error: Invalid file extension", 2);
	return (1);
}

static int check_file_exists(char *archive)
{
	int fd;

	ft_putendl_fd("SUKA BLYAT", 2);
	fd = open(archive, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error: File does not exist", 2);
		return (1);
	}
	close(fd);
	ft_putendl_fd("locoooo BLYAT", 2);
	return (0);
}

static int	load_textures(char *archive, t_data *data)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open(archive, O_RDONLY);
	line = get_next_line(fd);
	while (line > 0)
	{
		if (line[0] == 'N' && line[1] == 'O')
			data->mapinfo->no_path = ft_substr(line, 2, ft_strlen(line)-1);
		if (line[0] == 'S' && line[1] == 'O')
			data->mapinfo->so_path = ft_substr(line, 2, ft_strlen(line)-1);
		if (line[0] == 'W' && line[1] == 'E')
			data->mapinfo->we_path = ft_substr(line, 2, ft_strlen(line)-1);
		if (line[0] == 'E' && line[1] == 'A')
			data->mapinfo->ea_path = ft_substr(line, 2, ft_strlen(line)-1);
		if (line[0] == 'F' && line[1] == ' ')
			data->mapinfo->floor_color = 3;//ft_strdup(line + 2);
		if (line[0] == 'C' && line[1] == ' ')
			data->mapinfo->ceiling_color = 88;//ft_strdup(line + 2);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (i != 5 || !data->mapinfo->no_path || !data->mapinfo->so_path
		|| !data->mapinfo->we_path || !data->mapinfo->ea_path
		|| !data->mapinfo->floor_color || !data->mapinfo->ceiling_color)
		return (ft_putendl_fd("Error: Missing information", 2), 1);
	return (0);
}

int	parsemap(char *archive, t_data *data)
{	
	if (check_file_extension(archive) || check_file_exists(archive))
	{
		ft_putstr_fd("basuron\n", 1);
		return (1);
	}
	if (load_textures(archive, data))
	{
		ft_putstr_fd("textura en tu cara\n", 1);
		//return (1);
	}

	printf("NO: %s\n", data->mapinfo->no_path);
	printf("SO: %s\n", data->mapinfo->so_path);
	printf("WE: %s\n", data->mapinfo->we_path);
	printf("EA: %s\n", data->mapinfo->ea_path);
	printf("F: %d\n", data->mapinfo->floor_color);
	printf("C: %d\n", data->mapinfo->ceiling_color);

	return (0);
}