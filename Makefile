# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avishnev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/26 17:53:06 by avishnev          #+#    #+#              #
#    Updated: 2018/01/11 14:16:58 by avishnev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAG = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror -o $(NAME)
LIB = ./libft/
SRC = ./src/*.c
INC = ./includes

all: $(NAME)
$(NAME):
	@make -C $(LIB) --silent
	@gcc $(FLAG) $(SRC) $(LIB)libft.a -I $(INC)
	@echo "<<<<<<<<<<<<<<<<--FDF_COMPILED-->>>>>>>>>>>>>>>>"
norm:
	@norminette ./src/
	@norminette ./includes/
clean:
	@make -C $(LIB) clean --silent
	@echo "<<<<<<<<<<<<<<<<--Succes-->>>>>>>>>>>>>>>>"
fclean: clean
	@make -C $(LIB) fclean --silent
	@rm -f $(NAME)
re: fclean all
