#ifndef CUB3D_H
# define CUB3D_H

/* =============================== LIBRARIES =============================== */
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# include "libft.h"
# include "get_next_line.h"
# include "MLX42/MLX42.h"

/* =============================== CONSTANTS =============================== */

# define WIDTH 640
# define HEIGHT 480

# define TEX_SIZE 64

# define COLLIDER_DISTANCE 1.25

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define CEILING 4
# define FLOOR 5

# define ROT_SPEED 0.015
# define MOV_SPEED 0.035

# define SPECIAL_CHARS "\t\f\r\n\v "

/* =============================== ERROR_MSG =============================== */
# define ARGS_ERR "Error\nWrong number of arguments"
# define MALLOC_ERR "Error\nMemory was not allocated"
# define INFO_ERR "Error\nMissing or too much information"
# define FILE_ERR "Error\nFile does not exist"
# define LOAD_ERR "Error\nUnable to load resource"
# define EXTENSION_ERR "Error\nInvalid file extension"
# define INVALID_MAP "Error\nInvalid map"
# define DUPLICATE_ERR "Error\nDuplicated information"
# define COLOR_ERR "Error\nColor must be in range [0, 255]"

/* ================================ STRUCTS ================================ */
typedef struct s_texture_info
{
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}	t_texture_info;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_raycast
{
	char	player_dir;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	int		draw_start;
	int		draw_end;
	double	perp_wall_dist;
	int		line_height;
	double	wall_x;
}	t_ray;

typedef struct s_map_info
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*floor_color_rgb;
	char			*ceiling_color_rgb;
	unsigned int	hex_floor;
	unsigned int	hex_ceiling;
}	t_map_info;

typedef struct s_data
{
	mlx_t			*mlx;
	char			**map;
	t_map_info		*map_info;
	mlx_image_t		*game_img;
	mlx_image_t		*bg_img;
	t_ray			*ray;
	t_player		*player;
	mlx_texture_t	*textures[4];
	t_texture_info	*tex_info;
	int				fd;
	char			**file;
}	t_data;

/* ================================= PARSER ================================= */

void			parsemap(char *archive, t_data *data);
void			enter_map(t_data *data);
void			load_file(char *file, t_data *data);
unsigned int	convert_to_hex(int r, int g, int b);
void			load_color(t_data *data, char *line);
void			load_textures(t_data *data, char *line);
void			check_already_loaded(t_data *data, int option);

/* ================================ MOVEMENT ================================ */

void			move_player(void *game_data);
void			get_player_orientation(t_player *player, t_ray *ray);
void			rotate_player(t_data *data, int dir);

/* ================================= RENDER ================================= */
void			render_game(t_data *data);
void			textures_calculation(t_data *data, t_ray *ray,
					t_player *player, int x);
void			print_ceiling_floor(t_data *data);
void			clean_img(t_data *data);

/* ================================= UTILS ================================= */
void			init_data(t_data *data);
void			free_and_exit(t_data *data, int exit_code_number);
void			free_colors(char **colors, int *rgb);

/* ================================= BONUS ================================= */
void			check_valid_position(t_data *data, double x, double y);

extern int		map[12][12]; //TODO

#endif
