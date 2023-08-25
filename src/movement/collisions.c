#include "cub3d.h"

static int	is_valid_pos(t_data *data, double x, double y)
{
	(void) data;

	return (x >= COLLIDER_DISTANCE && y >= COLLIDER_DISTANCE
		&& x <= /*data->map_info->width*/ 12 - COLLIDER_DISTANCE
		&& y <= /*data->map_info->height*/ 12 - COLLIDER_DISTANCE
		&& map[(int) x][(int) y] == 0);
}

void	check_valid_position(t_data *data, double x, double y)
{
	if (is_valid_pos(data, x, data->player->pos_y)
		&& is_valid_pos(data, data->player->pos_x, y))
	{
		data->player->pos_x = x;
		data->player->pos_y = y;
	}
}
