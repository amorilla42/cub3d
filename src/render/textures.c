/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:47:31 by amorilla          #+#    #+#             */
/*   Updated: 2023/08/26 20:47:32 by amorilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_img(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			mlx_put_pixel(data->game_img, x, y, 0);
	}
}

void	print_ceiling_floor(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(data->bg_img, x, y, data->map_info->hex_ceiling);
			else
				mlx_put_pixel(data->bg_img, x, y, data->map_info->hex_floor);
		}
	}
}

static int	get_texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			return (WEST);
		else
			return (EAST);
	}
	else if (ray->dir_y > 0)
		return (SOUTH);
	return (NORTH);
}

static void	print_map(t_data *data, t_ray *ray, int x)
{
	int				y;
	t_texture_info	*tex;
	uint8_t			*pixels;
	int32_t			color;
	int				texture_index;

	tex = data->tex_info;
	y = ray->draw_start - 1;
	while (++y < ray->draw_end)
	{
		tex->tex_y = (int)(tex->tex_pos) & (TEX_SIZE - 1);
		tex->tex_pos += tex->step;
		texture_index = get_texture_index(ray);
		pixels = &data->textures[texture_index]
			->pixels[TEX_SIZE * tex->tex_y * 4 + tex->tex_x * 4];
		color = pixels[0] << 24 | pixels[1] << 16 | pixels[2] << 8 | pixels[3];
		mlx_put_pixel(data->game_img, x, y, color);
	}
}

void	textures_calculation(t_data *data, t_ray *ray, t_player *player, int x)
{
	t_texture_info	*tex;

	tex = data->tex_info;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	tex->tex_x = (int)(ray->wall_x * (double) TEX_SIZE);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		tex->tex_x = TEX_SIZE - tex->tex_x - 1;
	tex->step = 1.0 * TEX_SIZE / ray->line_height;
	tex->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* tex->step;
	print_map(data, ray, x);
}
