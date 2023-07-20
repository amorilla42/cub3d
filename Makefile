NAME	= cub3d
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=42 #-g -fsanitize=address
HEADERS = -I $(GNL_DIR) -I $(LIBMLX)/include/MLX42 -I $(LIBFT)
LIBS	= -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
#LIBS_LINUX = -ldl -lglfw -pthread -lm
# =================================================================================

SRC_DIR = src/
LIBMLX	= libs/MLX42
LIBFT	= libs/libft
GNL_DIR	= libs/get_next_line/
PARSER_DIR = src/parser/
# =================================================================================

PARSER_FILES = parsemap.c
PARSER_SRCS  = $(addprefix $(PARSER_DIR), $(PARSER_FILES))

GNL_FILES = get_next_line.c get_next_line_utils.c
GNL_SRCS  = $(addprefix $(GNL_DIR), $(GNL_FILES))

#FILES	 = cub3d.c
SRCS	 = $(addprefix $(SRC_DIR), $(FILES)) cub3d.c $(GNL_SRCS) $(PARSER_SRCS)

OBJS = $(SRCS:.c=.o)
# =================================================================================

all: libft libmlx $(NAME)

libft:
	make -C $(LIBFT)

libmlx:
	make -C $(LIBMLX)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS) $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a $(HEADERS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(LIBMLX)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)/libft.a
	rm -rf $(LIBMLX)/libmlx42.a

re: fclean all

.PHONY: all clean fclean re libmlx libft