# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 22:06:46 by hbettal           #+#    #+#              #
#    Updated: 2024/07/30 00:02:47 by hbettal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror 

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

 NAME = cub3d

HEADER = cub3d.h

OBJ =	cub3d.o		init.o		mlx_helper.o		GNL/get_next_line.o		GNL/get_next_line_utils.o

all: $(NAME)
	@echo "\033[1;32mCompilation Completed Successfully! ✅\033[0;m"

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) $(MLX_FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	@echo "\033[0;36mCompiling $< .\033[0;m"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[0;31mRemoving object files.\033[0;m"

	@echo "\033[0;31mRemoving object files.\033[0;m"

	@rm -f $(OBJ)
	@echo "\033[1;32mCleaning DONE ✅\033[0;m"

fclean: clean
	@echo "\033[0;31mRemoving program.\033[0;m"
	@echo "\033[1;32mDONE ✅\033[0;m"
	@rm -f $(NAME)

re: fclean all 

.PHONY: clean