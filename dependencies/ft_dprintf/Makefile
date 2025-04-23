# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 10:53:45 by acaetano          #+#    #+#              #
#    Updated: 2025/04/05 09:22:08 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME

NAME		= $(LIB_DIR)/libft_dprintf.a

OBJS_DIR 	= ./objects
SRCS_DIR	= ./sources
INC_DIR		= ./include
INCLUDE		= ./include/ft_dprintf.h
LIB_DIR		= ../../build

SRCS		= ft_dprintf.c \
			  ft_putchar_dpf.c \
			  ft_putnbr_dpf.c \
			  ft_putnbr_lbase_dpf.c \
			  ft_putnbr_ubase_dpf.c \
			  ft_putptr_dpf.c \
			  ft_putstr_dpf.c \
			  ft_putunbr_dpf.c \

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# COMPILATION

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INC_FLAG	= -I $(INC_DIR) 

all: objects $(LIB_DIR) $(NAME)

objects:
	mkdir -p $(OBJS_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(NAME): $(OBJS) 
	ar rc $(NAME) $(OBJS)
	
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDE)
	$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all re clean fclean
