#include "../../cub3d.h"

static int	check_file_extension(char *archive)
{
	size_t	len;

	len = (int)ft_strlen(archive);
	if((len > 4) && (archive[len - 4] == '.')
		&& (archive[len - 3] == 'c')
		&& (archive[len - 2] == 'u')
		&& (archive[len - 1] == 'b'));
		return (1);
	ft_putendl_fd("Error: Invalid file extension", 2);
	return (0);
}

static int check_file_exists(char *archive)
{
	int fd;

	fd = open(archive, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error: File does not exist", 2);
		return (1);
	}
	close(fd);
	return (0);
}

static int	load_textures(char *archive, t_data *data){
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open(archive, O_RDONLY);
	while (line = ft_get_next_line(fd) > 0)
	{
		if (line[0] == 'N' && line[1] == 'O')
		{
			data->north_texture = ft_strdup(line + 2);
			i++;
		}
		if (line[0] == 'S' && line[1] == 'O')
		{
			data->south_texture = ft_strdup(line + 2);
			i++;
		}
		if (line[0] == 'W' && line[1] == 'E')
		{
			data->west_texture = ft_strdup(line + 2);
			i++;
		}
		if (line[0] == 'E' && line[1] == 'A')
		{
			data->east_texture = ft_strdup(line + 2);
			i++;
		}
		if (line[0] == 'S' && line[1] == ' ')
		{
			data->sprite_texture = ft_strdup(line + 2);
			i++;
		}
		if (line[0] == 'F' && line[1] == ' ')
		{
			data->floor_color = ft_strdup(line + 2);
			i++;
		}
		if (line[0] == 'C' && line[1] == ' ')
		{
			data->ceiling_color = ft_strdup(line + 2);
			i++;
		}
		if (line[0] == 'R' && line[1] == ' ')
		{
			data->resolution = ft_strdup(line + 2);
			i++;
		}
	}
	if (i != 8)
	{
		ft_putendl_fd("Error: Missing information", 2);
		return (1);
	}
	return (0);
}


int	parsemap(char *archive, t_data *data)
{	
	if (!check_file_extension(archive) || !check_file_exists(archive))
	{
		return (1);
	}
	load_textures(archive, data);


	return (0);
}