/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:45:05 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/26 20:50:30 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_data *data)
{
	double	x;
	double	y;

	x = data->player->pos_x + data->player->dir_x * MOV_SPEED;
	y = data->player->pos_y + data->player->dir_y * MOV_SPEED;
	check_valid_position(data, x, y);
}

static void	move_left(t_data *data)
{
	double	x;
	double	y;

	x = data->player->pos_x + data->player->dir_y * MOV_SPEED;
	y = data->player->pos_y - data->player->dir_x * MOV_SPEED;
	check_valid_position(data, x, y);
}

static void	move_backward(t_data *data)
{
	double	x;
	double	y;

	x = data->player->pos_x - data->player->dir_x * MOV_SPEED;
	y = data->player->pos_y - data->player->dir_y * MOV_SPEED;
	check_valid_position(data, x, y);
}

static void	move_right(t_data *data)
{
	double	x;
	double	y;

	x = data->player->pos_x - data->player->dir_y * MOV_SPEED;
	y = data->player->pos_y + data->player->dir_x * MOV_SPEED;
	check_valid_position(data, x, y);
}

void	move_player(void *game_data)
{
	t_data	*data;

	data = (t_data *) game_data;
	clean_img(data);
	render_game(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		free_and_exit(data, EXIT_SUCCESS);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_forward(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_backward(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_player(data, -1);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_player(data, 1);
}
