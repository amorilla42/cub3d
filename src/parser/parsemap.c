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

static void	check_already_loaded(t_data *data, int option)
{
	if (data->map_info->no_path && option == NORTH)
	{
		ft_putendl_fd(DUPLICATE_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	else if (data->map_info->we_path && option == WEST)
	{
		ft_putendl_fd(DUPLICATE_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	else if (data->map_info->ea_path && option == EAST)
	{
		ft_putendl_fd(DUPLICATE_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	else if (data->map_info->so_path && option == SOUTH)
	{
		ft_putendl_fd(DUPLICATE_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

static void	load_textures(t_data *data, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		check_already_loaded(data, NORTH);
		data->map_info->no_path = ft_strtrim(line + 2, SPECIAL_CHARS);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		check_already_loaded(data, SOUTH);
		data->map_info->so_path = ft_strtrim(line + 2, SPECIAL_CHARS);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		check_already_loaded(data, WEST);
		data->map_info->we_path = ft_strtrim(line + 2, SPECIAL_CHARS);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		check_already_loaded(data, EAST);
		data->map_info->ea_path = ft_strtrim(line + 2, SPECIAL_CHARS);
	}
}

static void	load_color(t_data *data, char *line)
{
	char	*aux;
	char	**aux2;

	// 1: trim de line+1 y guardar en aux
	// 2  split de aux por ',' y guardar en aux2
	// 3: free aux
	// 4: trim de cada posicion de aux2
	// 5: hacerle atoi de cada posicion de aux2 y mirar si es de 0 a 255
	// 6: convertir a hexadecimal cada posicion de aux2 y juntarlo en un unico valor?????
	// 7: guardar en data->map_info->hex_floor o hex_ceiling
	// 8: free aux2
	
	if (line[0] == 'C')
	{
		check_already_loaded(data, CEILING);
		aux = ft_strtrim(line + 1, SPECIAL_CHARS);
	}
	else if (line[0] == 'F')
	{
		check_already_loaded(data, FLOOR);
		data->map_info->floor_color_rgb = ft_strtrim(line + 1, SPECIAL_CHARS);
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






static void true_parser(t_data *data)
{
	int	i;

	i = 0;
	while (data->file[i])
	{
		if (load_map_params(data, data->file[i]))
		{
			i++;
			continue ;
		}
		if (load_map(data, i))
			break ;
		i++;

	}
	
}





void	parsemap(char *archive, t_data *data)
{
	data->fd = open(archive, O_RDONLY);
	load_file(archive, data);
	check_file(data, archive);
	load_textures(data);
	enter_map(data);
}
