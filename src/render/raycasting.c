#include "cub3d.h"

static void	calculate_heights(t_ray *ray)
{
	if (!(ray->side))
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int) HEIGHT / ray->perp_wall_dist;
	ray->draw_start = -(ray->line_height) / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

static void	execute_dda(t_data *data, t_ray *ray)
{
	int		hit;

	hit = 0;
	(void) data;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_x][ray->map_y] != '0'
			&& !ft_strchr("NSWE", data->map[ray->map_x][ray->map_y]))
				hit = 1;
	}
}

static void	calculate_euclidean_distance(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

static void	set_raycast_info(t_data *data, int x)
{
	double		camera_x;
	t_ray		*ray;
	t_player	*player;

	ray = data->ray;
	player = data->player;
	camera_x = 2 * x / (double) WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * camera_x;
	ray->dir_y = player->dir_y + player->plane_y * camera_x;
	ray->map_x = (int) player->pos_x;
	ray->map_y = (int) player->pos_y;
	if (ray->dir_x == 0)
		ray->delta_dist_x = INFINITE;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = INFINITE;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	calculate_euclidean_distance(ray, player);
}

void	render_game(t_data *data)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		set_raycast_info(data, x);
		execute_dda(data, data->ray);
		calculate_heights(data->ray);
		textures_calculation(data, data->ray, data->player, x);
	}
}
