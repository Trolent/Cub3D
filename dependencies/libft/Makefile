# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trolland <trolland@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 15:03:39 by acaetano          #+#    #+#              #
#    Updated: 2025/04/14 16:35:18 by trolland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= $(LIB_DIR)/libft.a

OBJS_DIR	= ./objects
SRCS_DIR	= ./sources
INC_DIR		= ./include
INCLUDE		= ./include/libft.h
LIB_DIR		= ../../build

SRCS 		=	ft_atoi.c \
				ft_atos.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_freetab.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
	   			ft_isdigit.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_isseparator.c \
				ft_itoa.c \
				ft_max.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
	   			ft_memmove.c \
				ft_memset.c \
				ft_modf.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
	   			ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strndup.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_tabjoin.c \
				ft_tabsize.c \
	   			ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_strnstr.c \
	   			ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				get_next_line.c \
				get_next_line_utils.c \

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# COMPILATION

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -gdwarf-4
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
