# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 22:16:26 by kbahrar           #+#    #+#              #
#    Updated: 2019/06/19 19:58:57 by kbahrar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
OBJ = del_lst.o error.o fillit.o ft_conver_index.o ft_convert_case.o ft_copie_tetris.o ft_delsplit.o ft_finalvalid.o ft_get_index.o ft_index_debut.o ft_lstterm.o ft_make_tetris.o ft_putres.o ft_readtet.o ft_show_usage.o ft_stock_tetriminos.o ft_valid.o ft_validall.o get_next_index.o index_to_nwl.o
SRC = src/del_lst.c src/error.c src/fillit.c src/ft_conver_index.c src/ft_convert_case.c src/ft_copie_tetris.c src/ft_delsplit.c src/ft_finalvalid.c src/ft_get_index.c src/ft_index_debut.c src/ft_lstterm.c src/ft_make_tetris.c src/ft_putres.c src/ft_readtet.c src/ft_show_usage.c src/ft_stock_tetriminos.c src/ft_valid.c src/ft_validall.c src/get_next_index.c src/index_to_nwl.c
LIBFT = libft

all:$(NAME)

$(NAME):
	@make all clean -C $(LIBFT)
	@gcc -c $(FLAGS) $(SRC)
	@ar rc fillit.a $(OBJ)
	@gcc $(FLAGS) src/main.c $(LIBFT)/libft.a fillit.a -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)
	@rm -rf fillit.a

re: fclean all