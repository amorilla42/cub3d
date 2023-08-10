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
	int		floor_color_R;		//suelo color red
	int		floor_color_G;		//suelo color green
	int		floor_color_B;		//suelo color blue
	int		ceiling_color_R;	//techo color red
	int		ceiling_color_G;	//techo color green
	int		ceiling_color_B;	//techo color blue
}	t_mapinfo;

typedef struct s_data
{
	mlx_t		*mlx;
	void		*win;	//ventana pa algo del mlx???? no se sabe, si se tiene que quitar se quita a la chingada verga valiendo verga todo :v no mames wey
	int			win_height; //altura de la ventana
	int			win_width;	//ancho de la ventana
	t_mapinfo	*mapinfo;	//informacion del mapa
	char		**map;	//mapa matriz????
}	t_data;



//***    PARSER     ***//

int	parsemap(char *archive, t_data *data);
int	enter_map(char *archive, t_data *data);


//***    UTILS ??????????    ***//

void	press_key(mlx_key_data_t keydata, void	*game_data);
void	free_and_exit(t_data *data, int exit_code_number);











# endif
