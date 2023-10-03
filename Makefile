# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:29:37 by snocita           #+#    #+#              #
#    Updated: 2023/04/09 11:33:26 by snocita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ./includes/fractol.h

LIBFT	= ./libs/libft/
MLX		:= ./libs/minilibx-linux/

SRCS	=	src/colors.c \
			src/equations.c \
			src/initialization.c \
			src/key_oper.c \
			src/main.c \
			src/mouse_oper.c

# CROSS PLATFORM SUPPORT

OS := $(shell uname -s)

ifeq ($(OS), Windows_NT)
	NAME := $(addsuffix .exe, $(NAME))
else ifeq ($(OS), Darwin)
	MLX_DIR = libs/minilibx-linux/libmlx.a
	LIBFLAGS = -framework OpenGL -framework AppKit -lm -I -L/libs/minilibx-linux/libmlx_linux.a
endif

OBJS	=	$(SRCS:.c=.o)

UNAME = $(shell uname -s)

ifeq ($(UNAME),Linux)
	VALGRIND = valgrind -q --leak-check=full --track-origin=yes
else 
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

all:  libft mlx $(NAME) norminette exec

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBFT)
	@echo "Compilation of Libft:	\033[1;32mOK\033[m"

mlx:
	@echo "Compiling MLX with according OS -> ($(OS))"
	@$(MAKE) -C $(MLX)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) $(MLX_DIR) $(LIBFT)libft.a -o $(NAME)
	@echo "Compilation of Fractol:	\033[1;32mSUCCESS\033[m"

norminette:
	@echo "\n"
	@echo "CHECKING NORMINETTE...\n"
	@echo "\t"
	@norminette src/*.c libs/libft/*.c includes/*
	@echo "\n"
	@echo "\n"

exec:
	@echo "Catalyzing fractol PROMPT..."
	@./fractol

clean:
	@echo " Trashing Away objects....."
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(MLX) clean
	@echo "Cleaning Done"

fclean: clean
	@rm -f $(NAME) 
	@echo "Trashing Away all objects and library...."
	
re: fclean all

.phony: all libft clean fclean mlx