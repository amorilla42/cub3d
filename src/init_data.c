#include "cub3d.h"

static void	init_textures(t_data *data)
{
	data->textures[NORTH] = mlx_load_png(data->map_info->no_path);
	if (!data->textures[NORTH])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->textures[SOUTH] = mlx_load_png(data->map_info->so_path);
	if (!data->textures[SOUTH])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->textures[EAST] = mlx_load_png(data->map_info->ea_path);
	if (!data->textures[EAST])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->textures[WEST] = mlx_load_png(data->map_info->we_path);
	if (!data->textures[WEST])
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
}

static void	init_images(t_data *data)
{
	data->game_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->game_img)
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->bg_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->bg_img)
	{
		ft_putendl_fd(LOAD_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	mlx_image_to_window(data->mlx, data->bg_img, 0, 0);
	mlx_image_to_window(data->mlx, data->game_img, 0, 0);
}

static void	init_structures(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_ray));
	if (!(data->ray))
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->ray->player_dir = 'N'; // TODO
	data->player = ft_calloc(1, sizeof(t_player));
	if (!(data->player))
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
	data->player->pos_x = 5; // TODO
	data->player->pos_y = 10; // TODO
	get_player_orientation(data->player, data->ray);
	data->tex_info = ft_calloc(1, sizeof(t_texture_info));
	if (!(data->tex_info))
	{
		ft_putendl_fd(MALLOC_ERR, STDERR_FILENO);
		free_and_exit(data, EXIT_SUCCESS);
	}
}

void	init_data(t_data *data)
{
	init_structures(data);
	init_images(data);
	init_textures(data);
}
