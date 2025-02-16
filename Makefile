# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 11:32:43 by trolland          #+#    #+#              #
#    Updated: 2025/02/16 12:27:59 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	:=	cub3d
LIBFT	:= 	libft/libft.a

SRC		:=	main.c								\
			

SRC_DIR	:=	src
BUILD	:=	.build
SRC 	:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ 	:=	$(patsubst $(SRC_DIR)/%.c, $(BUILD)/%.o, $(SRC))
DEPS 	:=	$(OBJ:.o=.d)

CC		:=	cc 
CFLAGS	:=	-Wall -Werror -Wextra -MMD -MP -Iinclude -Ilibft/include -I$(MLX_PATH) -g

MLX_LINUX =	Minilibx/minilibx-linux/libmlx.a 
MLX_MACOS = Minilibx/minilibx_macos/libmlx.a

OS := $(shell uname)
ifeq ($(OS),Darwin)
    $(info Using macOS configuration)
    MLX_TARGET = $(MLX_MACOS)
    MLX_PATH = Minilibx/minilibx_macos
    LDFLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
else
    MLX_TARGET = $(MLX_LINUX)
    MLX_PATH = Minilibx/minilibx-linux
    LDFLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz
endif


all: create_dirs $(NAME)

create_dirs:
	@mkdir -p $(BUILD)

$(NAME): $(MLX_TARGET) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(MLX_TARGET):
	@$(MAKE) --no-print-directory -C $(MLX_PATH) > /dev/null 2>&1
	@printf "\033[1;32mCompiled: $(MLX_PATH) \033[0m\n";

$(BUILD)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[1;32mCompiled: $<\033[0m\n";

$(LIBFT):
	@$(MAKE) --no-print-directory -C libft

clean:
	@if [ -d "$(BUILD)" ]; then $(RM) -rf "$(BUILD)" && echo "\033[1;31mDeleted: $(BUILD)\033[0m"; fi
	@$(MAKE) --no-print-directory clean -C libft > /dev/null 2>&1
	@echo "\033[1;31mDeleted: libft/obj\033[0m"

fclean: clean
	@if [ -f $(NAME) ]; then $(RM) -rf $(NAME) && echo "\033[1;31mDeleted: $(NAME)\033[0m"; fi
	@$(MAKE) --no-print-directory fclean -C libft > /dev/null 2>&1
	@echo "\033[1;31mDeleted: $(LIBFT)\033[0m"
	@$(MAKE) --no-print-directory clean -C $(MLX_PATH) > /dev/null 2>&1
	@echo "\033[1;31mDeleted: $(MLX_TARGET)\033[0m"

re: fclean all

-include $(DEPS)

.PHONY: all create_dirs clean fclean re
