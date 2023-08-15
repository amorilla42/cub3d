#include "../cub3d.h"


static void    free_map_struct(t_data *data)
{
    if(data->mapinfo->no_path)
        free(data->mapinfo->no_path);
    if(data->mapinfo->so_path)
        free(data->mapinfo->so_path);
    if(data->mapinfo->we_path)
        free(data->mapinfo->we_path);
    if(data->mapinfo->ea_path)
        free(data->mapinfo->ea_path);
    if(data->mapinfo->floor_color_rgb)
        free(data->mapinfo->floor_color_rgb);
    if(data->mapinfo->ceiling_color_rgb)
        free(data->mapinfo->ceiling_color_rgb);
    free(data->mapinfo);
}

void    free_all(t_data *data)
{
    if (data->mlx)
    {
        mlx_close_window(data->mlx);
        mlx_terminate(data->mlx);
    }
    if (data->mapinfo)
		free_map_struct(data);
	if (data->map)
		free_matrix(data);
	if (data->fd)
		close(data->fd);
    free(data);
}

void	print_err_exit(t_data *data, char *str)
{
	free_all(data);
	ft_putstr_fd(str, 2);
	exit(1);
}

