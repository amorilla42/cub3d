/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:45:57 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/26 20:46:12 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				continue ;
			else if (line[j] != '1')
			{
				ft_putendl_fd(MAP_ERR, STDERR_FILENO);
				free_and_exit(data, EXIT_FAILURE);
			}
		}
		map_surrounded_by_walls(data, line, j, i);
		j++;
	}
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

static void	search_extra_rows(t_data *data, int k)
{
	while (data->file[k])
	{
		if (!line_is_empty(data->file[k]))
		{
			ft_putendl_fd(MAP_ERR, STDERR_FILENO);
			free_and_exit(data, EXIT_FAILURE);
		}
		k++;
	}
}

static void	check_map_row(t_data *data, int i)
{
	if (!data->map[i])
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

void	check_map(t_data *data, int i)
{
	int	j;
	int	k;

	j = 0;
	k = i + data->map_info->height;
	data->map_info->width = get_max_width(data->file, i);
	while (data->file[i] && i < k)
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
	search_extra_rows(data, k);
	check_player(data);
	while (data->map[j])
	{
		check_line_by_line(data, data->map[j], j);
		j++;
	}
}
