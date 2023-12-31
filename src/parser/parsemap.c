/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:46:20 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/26 20:46:30 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*aux;

	aux = line;
	while (*aux && *aux != '\n')
	{
		while (ft_strchr(SPECIAL_CHARS, *aux))
			aux++;
		if (load_textures(data, aux))
			return (1);
		aux++;
	}
	return (0);
}

static void	check_all_loaded(t_data *data)
{
	if (!data->map_info->no_path
		|| !data->map_info->we_path
		|| !data->map_info->ea_path
		|| !data->map_info->so_path
		|| (data->map_info->floor_color_set != 1)
		|| (data->map_info->ceiling_color_set != 1)
		|| !data->map)
	{
		ft_putendl_fd(INFO_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

static int	load_colors(t_data *data, char *line)
{
	char	*tmp;

	tmp = line;
	while (*tmp && *tmp != '\n')
	{
		while (ft_strchr(SPECIAL_CHARS, *tmp))
			tmp++;
		if (load_color(data, tmp))
			return (1);
		tmp++;
	}
	return (0);
}

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
		else if (load_colors(data, data->file[i]))
		{
			i++;
			continue ;
		}
		else if (load_map(data, i))
			break ;
		i++;
	}
	check_all_loaded(data);
}
