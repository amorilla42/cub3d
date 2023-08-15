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


// WINDOW SIZE
# define WIDTH 640
# define HEIGHT 480

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

# define ARGS_ERR "Error\nWrong number of arguments"
# define MALLOC_ERR "Error\nMemory was not allocated"

//***    STRUCTS     ***//

typedef struct s_mapinfo
{
	char	*no_path;			//north texture path
	char	*so_path;			//south texture path
	char	*we_path;			//west texture path
	char	*ea_path;			//east texture path
	char	*floor_color_rgb;	//suelo color 
	char	*ceiling_color_r;	//techo color 
}	t_mapinfo;

typedef struct s_data
{
	mlx_t		*mlx;
	int			fd;				//file descriptor
	char 		**file;			//archivo entero guardado como matriz
	t_mapinfo	*mapinfo;		//informacion del mapa
	char		**map;			//mapa matriz



//***    PARSER     ***//

int	parsemap(char *archive, t_data *data);
void	enter_map(char *archive, t_data *data);
void	load_file(char *file, t_data *data);


//***    UTILS ??????????    ***//

void	press_key(mlx_key_data_t keydata, void	*game_data);
void	free_all(t_data *data);
void	print_err_exit(t_data *data, char *str);










# endif
