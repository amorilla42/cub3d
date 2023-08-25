#include "cub3d.h"

static void	check_file(t_data *data, char *archive)
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

static int	load_map_params(t_data *data, char *line)
{
	int		i;
	char	*aux;

	i = 0;
	if (line && line[0] != '\n')
	{
		aux = ft_strtrim(line, SPECIAL_CHARS);
		load_textures(data, aux);
		load_color(data, aux);
		free(aux);
	}
	return (1);
}

/*static void	check_all_loaded(t_data *data)
{
	if (!data->map_info->no_path
		|| !data->map_info->we_path
		|| !data->map_info->ea_path
		|| !data->map_info->so_path
		|| !data->map_info->floor_color_rgb
		|| !data->map_info->ceiling_color_rgb)
	{
		ft_putendl_fd(INFO_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}*/

void	parsemap(char *archive, t_data *data)
{
	int	i;

	data->fd = open(archive, O_RDONLY);
	load_file(archive, data);
	check_file(data, archive);
	i = 0;
	while (data->file[i])
	{
		if (load_map_params(data, data->file[i]))
		{
			i++;
			continue ;
		}
		/*if (load_map(data, i))
			break ;*/
		i++;
	}
	//check_all_loaded(data);
}
