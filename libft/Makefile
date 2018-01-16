# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avishnev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 15:52:45 by avishnev          #+#    #+#              #
#    Updated: 2017/11/06 15:59:24 by avishnev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror -I. -c
FILES = *.c

OBJ = $(FILES:%.c=%.o)

all: $(NAME)
$(NAME):$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
$(OBJ): $(FILES)
	@gcc $(FLAGS) $(FILES)
	@echo "<<<<<<<<<<<<<<<<<<<--LIBFT_COMPILED-->>>>>>>>>>>>>>>>>>>>"
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all
