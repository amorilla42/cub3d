/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:45:15 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/26 20:51:02 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_player_exist(t_data *data, int players)
{
	if (players != 1)
	{
		ft_putendl_fd(PLAYER_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_FAILURE);
	}
}

void	check_player(t_data *data)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	init_structures(data);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_valid_elem(data->map[i][j]) == 2)
			{
				data->ray->player_dir = data->map[i][j];
				data->player->pos_x = (double) i + 0.5;
				data->player->pos_y = (double) j + 0.5;
				player++;
			}
			j++;
		}
		i++;
	}
	check_player_exist(data, player);
	get_player_orientation(data->player, data->ray);
}
