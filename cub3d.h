#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libs/MLX42/include/MLX42/MLX42.h"
# include "libs/libft/libft.h"
# include "libs/get_next_line/get_next_line.h"
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

typedef struct s_mapinfo
{
	int		res_width;
	int		res_height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*s_path;
	int		floor_color;
	int		ceiling_color;
}	t_mapinfo;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	*mapinfo;
	char		**map;
	//t_player	player;
	//t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	//t_texinfo	texinfo;
	//t_img		minimap;
}	t_data;


//***    PARSER     ***//

int	parsemap(char *archive, t_data *data);






# endif