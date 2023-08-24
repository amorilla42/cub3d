#include "cub3d.h"

static void	move_forward(t_player *player)
{
	player->pos_x += player->dir_x * MOV_SPEED;
	player->pos_y += player->dir_y * MOV_SPEED;
}

static void	move_left(t_player *player)
{
	player->pos_x += player->dir_y * MOV_SPEED;
	player->pos_y -= player->dir_x * MOV_SPEED;
}

static void	move_backward(t_player *player)
{
	player->pos_x -= player->dir_x * MOV_SPEED;
	player->pos_y -= player->dir_y * MOV_SPEED;
}

static void	move_right(t_player *player)
{
	player->pos_x -= player->dir_y * MOV_SPEED;
	player->pos_y += player->dir_x * MOV_SPEED;
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
		move_forward(data->player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data->player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_backward(data->player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data->player);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_player(data, -1);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_player(data, 1);
}
