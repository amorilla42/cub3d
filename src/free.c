#include "cub3d.h"

//TODO: LO COMENTADO DA SEG. FAULT
/*static void	free_map_info(char ***map, t_map_info **map_info)
{
	int	i;

	i = -1;
	if (*map)
	{
		while (++i < (*map_info)->res_width)
			free((*map)[i]);
		free(*map);
	}
	if ((*map_info)->no_path)
		free((*map_info)->no_path);
	if ((*map_info)->so_path)
		free((*map_info)->so_path);
	if ((*map_info)->ea_path)
		free((*map_info)->ea_path);
	if ((*map_info)->we_path)
		free((*map_info)->we_path);
	if ((*map_info)->s_path)
		free((*map_info)->s_path);
	if (*map_info)
		free(*map_info);
}*/

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
	//free_map_info(&data->map, &data->map_info);
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
