# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 00:01:59 by sdatskov          #+#    #+#              #
#    Updated: 2019/04/30 00:02:01 by sdatskov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

MLX_FL = -lmlx -framework OpenGL -framework AppKit

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INC_DIR = ./includes/

LIB_DIR = ./libft/

SRC = main.c\
	  brazenhem.c\
	  ft_error.c\
	  init.c\
	  iso_proection.c\
	  make_center.c\
	  manipulation.c\
	  print_map.c\
	  read_map.c\
	  validation.c\

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -L $(LIB_DIR) -lft $(MLX_FL)

$(OBJ_DIR):
	@mkdir obj

$(OBJ_DIR)%.o: %.c
	@gcc -c $(FLAGS) $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

vpath %.c $(SRC_DIR)
