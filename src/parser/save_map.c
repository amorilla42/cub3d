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
}

static void	check_if_map_exist(t_data *data)
{
	if (!data->map)
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

static int	contains_ones_or_zeros(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && !ft_strchr(SPECIAL_CHARS, line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(SPECIAL_CHARS, line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	get_map_height(char **file, int i)
{
	int	height;

	height = 0;
	while (file[i])
	{
		height++;
		i++;
	}
	return (height);
}

static int	get_max_width(char **file, int idx)
{
	int	max_len;
	int	aux;
	int	i;

	i = idx;
	aux = 0;
	max_len = 0;
	while (file[i])
	{
		aux = ft_strlen(file[i]);
		if (aux > max_len)
			max_len = aux;
		i++;
	}
	return (max_len);
}

static void	check_map_row(t_data *data, int i)
{
	if (!data->map[i])
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

static void	normalize_map(t_data *data, int i)
{
	while (data->col < data->map_info->width - 1)
	{
		if (!data->file[i][data->aux_idx])
		{
			data->map[data->row][data->col] = '.';
			data->col++;
			continue;
		}
		else if (ft_strchr(SPECIAL_CHARS, data->file[i][data->aux_idx]))
			data->map[data->row][data->col] = '.';
		else
			data->map[data->row][data->col] = data->file[i][data->aux_idx];
		data->col++;
		data->aux_idx = data->col;
	}
}

static int	is_valid_elem(char c)
{
	if (ft_strchr("01", c))
		return (1);
	else if (ft_strchr("NSEW", c))
		return (2);
	else
		return (0);
}

static void	check_player_exist(t_data *data, int players)
{
	if (players != 1)
	{
		ft_putendl_fd(PLAYER_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

static void	check_player(t_data *data)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_valid_elem(data->map[i][j]) == 2)
			{
				data->ray->player_dir = data->map[i][j];
				data->player->pos_x = i;
				data->player->pos_y = j;
				player++;
			}
			j++;
		}
		i++;
	}
	check_player_exist(data, player);
}

static void	map_surrounded_by_walls(t_data *data, char *line, int j, int i)
{
	if (!line[i])
		return ;
	if (is_valid_elem(line[i]) == 0)
	{
		ft_putendl_fd(INVALID_MAP, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	if (line[i] != '1')
	{
		if ((!line[j + 1] || line[j + 1] == '.')
			|| (!i || i == data->map_info->height - 1)
			|| (i > 0 && (is_valid_elem(data->map[i - 1][j]) == 0))
			|| (i < data->map_info->height - 1
				&& (is_valid_elem(data->map[i + 1][j]) == 0)))
		{
			ft_putendl_fd(INVALID_MAP, STDERR_FILENO);
			free_and_exit(data, EXIT_FAILURE);
		}
	}
}

static void	check_line_by_line(t_data *data, char *line, int i)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == '.')
		{
			while (line[j] == '.')
				j++;
			if (!line[j])
				continue;
			else if (line[j] != '1')
			{
				ft_putendl_fd(INVALID_MAP, STDERR_FILENO);
				free_and_exit(data, EXIT_FAILURE);
			}
		}
		map_surrounded_by_walls(data, line, j, i);
		j++;
	}
}

static void mapa_comprobar(t_data *data, int i)
{
	data->map_info->width = get_max_width(data->file, i);
	while (data->file[i])
	{
		data->col = 0;
		data->aux_idx = 0;
		data->map[data->row] = ft_calloc(sizeof(char),
				data->map_info->width + 1);
		check_map_row(data, data->row);
		normalize_map(data, i);
		data->map[data->row][data->map_info->width] = '\0';
		i++;
		data->row++;
	}
	data->map[data->row] = NULL;
	check_player(data);
	while (data->map[i])
	{
		check_line_by_line(data, data->map[i], i);
		i++;
	}
}

int	load_map(t_data *data, int i)
{
	while (line_is_empty(data->file[i]))
		i++;
	while (!contains_ones_or_zeros(data->file[i]))
		return (0);
	data->map_info->height = get_map_height(data->file, i);
	data->map = ft_calloc(sizeof(char *), data->map_info->height + 1);
	check_if_map_exist(data);
	mapa_comprobar(data, i);
	return (1);
}
