# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gficara <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 17:25:41 by gficara           #+#    #+#              #
#    Updated: 2017/12/20 12:04:17 by gficara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

CC = gcc

SRC =	ft_tetadd.c \
		ft_tetnew.c \
		ft_srcsqr.c \
		ft_makesq.c \
		ft_find_sqrt.c \
		ft_fillsquare.c \
		ft_mkfl.c \
		ft_frsqr.c \
		ft_tetcheck.c \
		ft_error.c \
		ft_tettab.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) Makefile
	@make libft.a -C libft
	@ar rc $(NAME).a $(OBJ)
	@ranlib $(NAME).a
	@$(CC) $(FLAGS) ft_tetread.c fillit.a libft/libft.a -o $(NAME)
	@echo "Creating fillit"

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $< -g

clean :
	@make clean -C libft
	@rm -rf $(OBJ)
	@echo "Removing objects"

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME).a
	@rm -rf $(NAME)
	@echo "Removing"

re: fclean all
