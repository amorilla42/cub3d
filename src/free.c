#include "cub3d.h"

static void    free_map_struct(t_data *data)
{
	t_map_info	*map_info;

	map_info = data->map_info;
    if(map_info->no_path)
        free(map_info->no_path);
    if(map_info->so_path)
        free(map_info->so_path);
    if(map_info->we_path)
        free(map_info->we_path);
    if(map_info->ea_path)
        free(map_info->ea_path);
    if(map_info->floor_color_rgb)
        free(map_info->floor_color_rgb);
    if(map_info->ceiling_color_rgb)
        free(map_info->ceiling_color_rgb);
    free(map_info);
}

static void	free_file_and_map_info(t_data *data)
{
	int	i;

	i = -1;
	if (data->fd)
		close(data->fd);
	if (data->file)
	{
		while (data->file[++i])
			free(data->file[i]);
		free(data->file);
	}
	i = -1;
	if (data->map)
	{
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
	}
	free_map_struct(data);
}

void	free_and_exit(t_data *data, int exit_code_number)
{
	if (data->textures[NORTH])
		mlx_delete_texture(data->textures[NORTH]);
	if (data->textures[SOUTH])
		mlx_delete_texture(data->textures[SOUTH]);
	if (data->textures[EAST])
		mlx_delete_texture(data->textures[EAST]);
	if (data->textures[WEST])
		mlx_delete_texture(data->textures[WEST]);
	if (data->player)
		free(data->player);
	if (data->ray)
		free(data->ray);
	if (data->tex_info)
		free(data->tex_info);
	free_file_and_map_info(data);
	if (data->game_img)
		mlx_delete_image(data->mlx, data->game_img);
	if (data->bg_img)
		mlx_delete_image(data->mlx, data->bg_img);
	if (data->mlx)
		mlx_close_window(data->mlx);
	if (data->mlx)
		mlx_terminate(data->mlx);
	free(data);
	exit(exit_code_number);
}

void	free_colors(char **colors, int *rgb)
{
	if (colors)
	{
		if (colors[0])
			free(colors[0]);
		if (colors[1])
			free(colors[1]);
		if (colors[2])
			free(colors[2]);
		free(colors);
	}
	if (rgb)
		free(rgb);
}
