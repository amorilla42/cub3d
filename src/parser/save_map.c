/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:46:50 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/26 20:46:51 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	contains_ones_or_zeros(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0'
			&& !ft_strchr(SPECIAL_CHARS, line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	get_map_height(char **file, int i)
{
	int	height;

	height = 0;
	while (file[i] && (file[i][0] != '\n'))
	{
		height++;
		i++;
	}
	return (height);
}

int	load_map(t_data *data, int i)
{
	while (data->file[i] && line_is_empty(data->file[i]))
		i++;
	if (!data->file[i])
		return (0);
	while (!contains_ones_or_zeros(data->file[i]))
		return (0);
	data->map_info->height = get_map_height(data->file, i);
	data->map = ft_calloc(sizeof(char *), data->map_info->height + 1);
	if (!data->map)
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	check_map(data, i);
	return (1);
}
