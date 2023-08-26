/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:46:36 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/26 20:46:42 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_is_empty(char *line)
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

int	is_valid_elem(char c)
{
	if (ft_strchr("01", c))
		return (1);
	else if (ft_strchr("NSEW", c))
		return (2);
	else
		return (0);
}

void	normalize_map(t_data *data, int i)
{
	while (data->col < data->map_info->width - 1)
	{
		if (!data->file[i][data->aux_idx])
		{
			data->map[data->row][data->col] = '.';
			data->col++;
			continue ;
		}
		else if (ft_strchr(SPECIAL_CHARS, data->file[i][data->aux_idx]))
			data->map[data->row][data->col] = '.';
		else
			data->map[data->row][data->col] = data->file[i][data->aux_idx];
		data->col++;
		data->aux_idx = data->col;
	}
}

void	map_surrounded_by_walls(t_data *data, char *line, int j, int i)
{
	if (!line[j])
		return ;
	if (is_valid_elem(line[j]) == 0)
	{
		ft_putendl_fd(MAP_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
	if (line[j] != '1')
	{
		if ((!line[j + 1] || line[j + 1] == '.')
			|| (!i || i == data->map_info->height - 1)
			|| (j == 0 || j == data->map_info->width - 1)
			|| (i > 0 && (is_valid_elem(data->map[i - 1][j]) == 0))
			|| ((i < data->map_info->height - 1)
				&& (is_valid_elem(data->map[i + 1][j]) == 0)))
		{
			ft_putendl_fd(MAP_ERR, STDERR_FILENO);
			free_and_exit(data, EXIT_FAILURE);
		}
	}
}
