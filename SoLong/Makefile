# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 13:00:36 by iggonzal          #+#    #+#              #
#    Updated: 2023/08/06 13:38:00 by iggonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SOURCE 	=	./src/libft/ft_stringjoin.c				\
			./src/libft/ft_itoa.c						\
			./src/libft/ft_strcmp.c						\
			./src/ft_get_map.c					\
			./src/ft_movement.c 					\
			./src/libft/ft_split.c						\
			./src/ft_put_image.c					\
			./src/ft_put_text.c					\
			./get_next_line/get_next_line_utils.c	\
			./get_next_line/get_next_line.c			\
			./src/ft_check_file_is_valid.c		\
			./src/ft_check_map_utils.c			\
			./src/ft_check_map.c					\
			./src/ft_exit_door.c					\
			so_long.c

LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all

