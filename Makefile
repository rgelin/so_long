# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 23:38:05 by rgelin            #+#    #+#              #
#    Updated: 2021/10/13 17:14:20 by rgelin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG_SRCS =		./src/main.c \
					./src/get_next_line/get_next_line.c \
					./src/get_next_line/get_next_line_utils.c \
					./src/get_map.c \
					./src/check_map.c \
					./src/window.c \
					./src/play_game.c \
					./src/movements.c \
					./src/free_and_destroy.c

SO_LONG_BONUS_SRCS =	./src/bonus/main_bonus.c \
						./src/get_next_line/get_next_line.c \
						./src/get_next_line/get_next_line_utils.c \
						./src/get_map.c \
						./src/check_map.c \
						./src/bonus/window_bonus.c \
						./src/bonus/play_game_bonus.c \
						./src/movements.c \
						./src/free_and_destroy.c \
						./src/bonus/ft_itoa.c

SO_LONG_OBJS =		$(SO_LONG_SRCS:%.c=%.o)

SO_LONG_BONUS_OBJS =	$(SO_LONG_BONUS_SRCS:%.c=%.o)

LIB_MLX			=	libmlx.dylib



CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror

MLX_FLAGS	=		-lmlx -framework OpenGL -framework AppKit

REMOVE		=		rm -f

NAME		=		so_long



GREEN		=		\x1b[32m

NO_COLOR	=		\x1b[0m



.c.o:
			@$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

all:		$(NAME)
			@echo "$(NO_COLOR)Minilibx $(GREEN)ready"
			@echo "$(NO_COLOR)so_long $(GREEN)ready"

bonus:		$(SO_LONG_BONUS_OBJS)
			@make -C minilibx
			@cp ./minilibx/libmlx.dylib ./
			@$(CC) $(CFLAGS) $(MLX_FLAGS) $(SO_LONG_BONUS_OBJS) $(LIB_MLX) -o $(NAME)
			@echo "$(NO_COLOR)Minilibx $(GREEN)ready"
			@echo "$(NO_COLOR)so_long $(GREEN)ready"

$(NAME):	$(SO_LONG_OBJS)
			@make -C minilibx
			@cp ./minilibx/libmlx.dylib ./
			@$(CC) $(CFLAGS) $(MLX_FLAGS) $(SO_LONG_OBJS) $(LIB_MLX) -o $(NAME)

clean:
			@make clean -C minilibx
			@$(REMOVE) $(SO_LONG_OBJS) $(SO_LONG_BONUS_OBJS)
			
fclean:		clean
			@make clean -C minilibx
			@$(REMOVE) $(NAME) $(LIB_MLX)

re:			fclean all

.PHONY:		all clean fclean re