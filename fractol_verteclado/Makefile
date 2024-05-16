# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfontene <yfontene@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 15:27:50 by yfontene          #+#    #+#              #
#    Updated: 2024/05/16 18:05:13 by yfontene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN    =    \033[0;32m
RED        =    \033[0;31m
YELLOW    =    \033[0;33m
END        =    \033[0m

NAME = fractol
HEADER = fractol.h
MINILIBX = minilibx-linux/libmlx.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC        = main.c \
          string_utils.c \
          render.c \
          movements.c \
          math_utils.c \
          create_mlx.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJ) 
		@$(CC) $(CFLAGS) $(OBJ) -L./minilibx-linux -lmlx -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm -lz -I$(HEADER) -o $(NAME)
	@echo "$(GREEN)fractol successfully compiled!$(END)"

$(MINILIBX):
	@make -C minilibx-linux

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re