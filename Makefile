# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 15:36:25 by acaetano          #+#    #+#              #
#    Updated: 2025/04/21 15:52:18 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                 GET_OS SPEC                                 #
# **************************************************************************** #

OS := $(shell uname)

ifeq ($(OS),Darwin)
    $(info Using macOS configuration)
    MINILIBX = ./dependencies/minilibx/minilibx_macos
    INC_MLX = -L $(MINILIBX) -lmlx -I $(MINILIBX) -framework OpenGL -framework AppKit
else
    MINILIBX = ./dependencies/minilibx/minilibx-linux
    INC_MLX = -L $(MINILIBX) -lmlx -I $(MINILIBX) -lXext -lX11 -lXfixes 
endif


# **************************************************************************** #
#								DEPENDENCIES								   #
# **************************************************************************** #

DPRINTF				= $(LIBS_PATH)/ft_dprintf.a
LIBFT				= $(LIBS_PATH)/libft.a


LIBS_PATH			= ./build
HEADER_LIBFT		= ./dependencies/libft/include/
HEADER_DPRINTF		= ./dependencies/ft_dprintf/include/

# **************************************************************************** #
#									CORE									   #
# **************************************************************************** #


NAME				= cub3d 
ODIR				= ./objects

SRC_PATH 			= ./sources
HEADER_PATH			= ./includes

HEADERS				= $(HEADER_PATH)/cub3d.h \
					  $(HEADER_PATH)/typedef.h

CC					= clang
CFLAGS				= -Wall -Werror -Wextra -g -gdwarf-4 -fno-builtin -fPIE -MMD
CMLX				= make -C $(MINILIBX) 
INC_FLAGS			= -I $(HEADER_LIBFT) -I $(HEADER_DPRINTF) -I $(HEADER_PATH) -I $(MINILIBX)

ifeq ($(OS),Darwin)
   CFLAGS += -D MACOS
else
   CFLAGS += -D LINUX
endif

SOURCES				= game_engine/cosinta.c \
					  game_engine/ray_casting.c \
					  game_engine/dda_algorithm.c \
					  game_engine/draw_slice.c \
					  game_engine/draw_slice_utils.c \
					  mini_map/mini_map.c \
					  mini_map/mini_map_player.c \
					  mini_map/mini_map_cone.c \
					  mini_map/mini_map_utils.c \
					  main/main.c \
					  mlx/init_mlx.c \
					  mlx/key_hooks.c \
					  mlx/key_press_release.c \
					  movement/backward.c \
					  movement/forward.c \
					  movement/interact.c \
					  movement/lateral.c \
					  movement/lateral2.c \
					  movement/mouse_motion.c \
					  movement/turn.c \
					  movement/utils.c \
					  parsing/check_arguments.c \
					  parsing/check_file_extension.c \
					  parsing/error.c \
					  parsing/get_data.c \
					  parsing/get_file.c \
					  parsing/get_map.c \
					  parsing/get_textures_paths.c \
					  parsing/map_element_utils.c \
					  parsing/map_validation.c \
					  parsing/set_colors.c \
					  parsing/set_player.c \
					  parsing/set_player_utils.c \
					  parsing/set_textures.c \
					  parsing/is_element.c \
					  parsing/door_text.c \
					  utils/ft_exit.c \
					  utils/ft_exit_utils.c \

OBJ					= $(addprefix $(ODIR)/, $(SOURCES:.c=.o))
DEP 				= $(OBJ:.o=.d)

all: $(DPRINTF) $(LIBFT) $(ODIR) $(OBJ) $(NAME) $(HEADERS) 

$(DPRINTF):
	make -C ./dependencies/ft_dprintf

$(LIBFT):
	make -C ./dependencies/libft

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@ 


$(NAME): $(ODIR) $(OBJ) $(HEADERS)
	$(CMLX) && $(CC) $(CFLAGS) $(OBJ) -L $(LIBS_PATH) -L /usr/lib -lm -lz -L ./build -lft_dprintf -lft $(INC_MLX) -o $(NAME)


clean:
	rm -rf $(ODIR)
	rm -rf $(LIBS_PATH)
	make clean -C ./dependencies/libft
	make clean -C ./dependencies/ft_dprintf
	make clean -C $(MINILIBX)

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./dependencies/libft
	make fclean -C ./dependencies/ft_dprintf

run: all
	clear && valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./cub3d

re: fclean all
	clear

-include $(DEP)

.PHONY: all re clean fclean
