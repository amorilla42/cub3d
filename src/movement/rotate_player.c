#include "cub3d.h"

void	rotate_player(t_data *data, int dir)
{
	t_player	*player;
	double		rotation;
	double		tmp;

	player = data->player;
	rotation = ROT_SPEED * dir;
	tmp = player->dir_x;
	player->dir_x = player->dir_x * cos(rotation)
		- player->dir_y * sin(rotation);
	player->dir_y = tmp * sin(rotation)
		+ player->dir_y * cos(rotation);
	tmp = player->plane_x;
	player->plane_x = player->plane_x * cos(rotation)
		- player->plane_y * sin(rotation);
	player->plane_y = tmp * sin(rotation)
		+ player->plane_y * cos(rotation);
}
