/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:45:53 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/26 20:45:54 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_texture(char *archive, t_data *data)
{
	int		fd;
	size_t	len;

	fd = open(archive, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	close(fd);
	len = (int)ft_strlen(archive);
	if (!((len > 4) && (archive[len - 4] == '.')
			&& (archive[len - 3] == 'p')
			&& (archive[len - 2] == 'n')
			&& (archive[len - 1] == 'g')))
	{
		ft_putstr_fd(EXTENSION_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

void	check_already_loaded(t_data *data, int option)
{
	if ((data->map_info->no_path && option == NORTH)
		|| (data->map_info->we_path && option == WEST)
		|| (data->map_info->ea_path && option == EAST)
		|| (data->map_info->so_path && option == SOUTH)
		|| ((data->map_info->floor_color_set > 0) && option == FLOOR)
		|| ((data->map_info->ceiling_color_set > 0) && option == CEILING))
	{
		ft_putendl_fd(DUPLICATE_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

int	load_textures(t_data *data, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		check_already_loaded(data, NORTH);
		data->map_info->no_path = ft_strtrim(line + 2, SPECIAL_CHARS);
		return (check_texture(data->map_info->no_path, data), 1);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		check_already_loaded(data, SOUTH);
		data->map_info->so_path = ft_strtrim(line + 2, SPECIAL_CHARS);
		return (check_texture(data->map_info->so_path, data), 1);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		check_already_loaded(data, WEST);
		data->map_info->we_path = ft_strtrim(line + 2, SPECIAL_CHARS);
		return (check_texture(data->map_info->we_path, data), 1);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		check_already_loaded(data, EAST);
		data->map_info->ea_path = ft_strtrim(line + 2, SPECIAL_CHARS);
		return (check_texture(data->map_info->ea_path, data), 1);
	}
	return (0);
}
