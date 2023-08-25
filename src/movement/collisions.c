#include "cub3d.h"

static int	is_valid_pos(t_data *data, double x, double y)
{
	return (x > COLLIDER_DISTANCE && y > COLLIDER_DISTANCE
		&& x < data->map_info->width - COLLIDER_DISTANCE * 2
		&& y < data->map_info->height - COLLIDER_DISTANCE
		&& (data->map[(int) x][(int) y] == '0'
		|| ft_strchr("NSEW", data->map[(int) x][(int) y])));
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
