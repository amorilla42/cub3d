#include "cub3d.h"

static void	check_colors_len(char **matrix, t_data *data)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	if (i != 3)
	{
		i = 0;
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
		ft_putendl_fd(INFO_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

static int	*malloc_rgb(void)
{
	int	*rgb;

	rgb = ft_calloc(sizeof(int), 3);
	if (!rgb)
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (rgb);
}

static char	**parse_colors(t_data *data, char *line)
{
	char	*aux;
	char	**colors;

	aux = ft_strtrim(line + 1, SPECIAL_CHARS);
	colors = ft_split(aux, ',');
	check_colors_len(colors, data);
	free(aux);
	aux = ft_strtrim(colors[0], SPECIAL_CHARS);
	free(colors[0]);
	colors[0] = aux;
	aux = ft_strtrim(colors[1], SPECIAL_CHARS);
	free(colors[1]);
	colors[1] = aux;
	aux = ft_strtrim(colors[2], SPECIAL_CHARS);
	free(colors[2]);
	colors[2] = aux;
	return (colors);
}

static void	convert_str_to_rgb(t_data *data, char **colors, int *rgb)
{
	rgb[0] = ft_atoi(colors[0]);
	rgb[1] = ft_atoi(colors[1]);
	rgb[2] = ft_atoi(colors[2]);
	if (rgb[0] < 0 || rgb[0] > 255
		|| rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
	{
		ft_putendl_fd(COLOR_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

void	load_color(t_data *data, char *line)
{
	char	**colors;
	int		*rgb;

	rgb = malloc_rgb();
	if (line[0] == 'C')
	{
		check_already_loaded(data, CEILING);
		colors = parse_colors(data, line);
		convert_str_to_rgb(data, colors, rgb);
		data->map_info->hex_ceiling = convert_to_hex(rgb[0], rgb[1], rgb[2]);
		free_colors(colors, rgb);
	}
	else if (line[0] == 'F')
	{
		check_already_loaded(data, FLOOR);
		colors = parse_colors(data, line);
		convert_str_to_rgb(data, colors, rgb);
		data->map_info->hex_floor = convert_to_hex(rgb[0], rgb[1], rgb[2]);
		free_colors(colors, rgb);
	}
}
