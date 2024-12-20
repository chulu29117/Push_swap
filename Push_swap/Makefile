# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clu <clu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 20:33:14 by clu               #+#    #+#              #
#    Updated: 2024/12/20 21:07:21 by clu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = Libft
FT_PRINTF = ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(FT_PRINTF)/ft_printf.a
SRC = src/main.c src/push_swap.c src/operations.c src/parsing.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(FT_PRINTF)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re