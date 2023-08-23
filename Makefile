# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 00:25:28 by jdomingu          #+#    #+#              #
#    Updated: 2023/08/23 18:07:16 by amorilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= cub3D
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=42 -g -fsanitize=address
HEADERS = -I $(SRC_DIR) -I $(GNL_DIR) -I $(LIBMLX)/include -I $(LIBFT)
LIBS_MAC = $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/
#LIBS_LINUX = $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm
# =================================================================================

LIBMLX	= libs/MLX42
LIBFT	= libs/libft
GNL_DIR	= libs/get_next_line/

SRC_DIR = src/
PARSER_DIR = src/parser/
RENDER_DIR = src/render/
MOVEMENT_DIR = src/movement/
# =================================================================================

GNL_FILES = get_next_line.c get_next_line_utils.c
GNL_SRCS  = $(addprefix $(GNL_DIR), $(GNL_FILES))

PARSER_FILES = parsemap.c save_map.c
PARSER_SRCS  = $(addprefix $(PARSER_DIR), $(PARSER_FILES))

RENDER_FILES = raycasting.c textures.c
RENDER_SRCS = $(addprefix $(RENDER_DIR), $(RENDER_FILES))

MOVEMENT_FILES = get_player_orientation.c move_player.c rotate_player.c
MOVEMENT_SRCS = $(addprefix $(MOVEMENT_DIR), $(MOVEMENT_FILES))

FILES	 = cub3d.c free.c init_data.c
SRCS	 = $(addprefix $(SRC_DIR), $(FILES)) $(GNL_SRCS) $(PARSER_SRCS) $(RENDER_SRCS) $(MOVEMENT_SRCS)

OBJS = $(SRCS:.c=.o)

# =================================================================================

all: libft libmlx $(NAME)

libft:
	make -C $(LIBFT)

libmlx:
	make -C $(LIBMLX)

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS) $(LIBS_MAC) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(LIBMLX)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)/libft.a
	rm -rf $(LIBMLX)/libmlx42.a
	rm -rf $(NAME).dSYM

re: fclean all

n:
	norminette src

.PHONY: all libft libmlx clean fclean re n
