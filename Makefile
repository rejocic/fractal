# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rejocic <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 14:57:14 by rejocic           #+#    #+#              #
#    Updated: 2018/11/12 09:44:58 by rejocic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = @gcc -Wall -Werror -Wextra -O2

FLAGS = -framework OpenGL -framework AppKit -lpthread -fsanitize=address

SRC = srcs/main.c srcs/fractals.c srcs/imagination.c srcs/commands.c \
srcs/thread1.c srcs/thread2.c

OBJS = $(SRC:.c=.o)

LIB = ./libft/libft.a

MLX = minilibx_macos/libmlx.a

.PHONY: clean, fclean, re, bug

all: $(NAME) $(LIB)

$(NAME): $(OBJS) $(LIB) $(MLX)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB) $(MLX)

$(OBJS): fractal.h

$(LIB):
	@cd libft && make

$(MLX):
	@cd minilibx_macos && make

bug: $(OBJS) $(LIB) $(MLX)
	$(CC) $(FLAGS) -o bug -g $(SRC) $(LIB) $(MLX)

clean:
	@cd libft && make clean
	@cd minilibx_macos && make clean
	@rm -rf bug.dSYM
	@rm -f $(OBJS)

fclean: clean
	@cd libft && make fclean
	@rm -rf bug
	@rm -rf $(NAME)

re: fclean all
