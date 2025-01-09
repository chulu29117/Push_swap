# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clu <clu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 20:33:14 by clu               #+#    #+#              #
#    Updated: 2025/01/09 22:11:05 by clu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = Libft
FT_PRINTF = ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(FT_PRINTF)/libftprintf.a
SRC = 	src/main.c \
		src/operations_1.c src/operations_2.c src/operations_3.c \
		src/input_check.c \
		src/parsing.c \
		src/stacks.c \
		src/sort_small.c \
		src/sort_large.c \
		src/errors.c \
		src/debug.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(FT_PRINTF) -c $< -o $@

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