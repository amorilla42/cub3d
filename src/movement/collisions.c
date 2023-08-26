#include "cub3d.h"

static int	is_valid_pos(t_data *data, double x, double y)
{
	return (x > 0.25 && y > 0.25
		&& x < data->map_info->height - COLLIDER_DISTANCE
		&& y < data->map_info->width - COLLIDER_DISTANCE
		&& ft_strchr("0NSEW", data->map[(int) x][(int) y]));
}

void	check_valid_position(t_data *data, double x, double y)
{
	if (is_valid_pos(data, x, data->player->pos_y))
		data->player->pos_x = x;
	if (is_valid_pos(data, data->player->pos_x, y))
		data->player->pos_y = y;
}
