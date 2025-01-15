# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clu <clu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 20:33:14 by clu               #+#    #+#              #
#    Updated: 2025/01/15 11:57:00 by clu              ###   ########.fr        #
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
		src/operations_swap.c \
		src/operations_push.c \
		src/operations_rot.c \
		src/operations_rrot.c\
		src/input_check.c \
		src/parsing.c \
		src/stacks.c \
		src/sort_utils.c \
		src/sort_small.c \
		src/sort_mid.c \
		src/sort_large.c \
		src/sort_array.c \
		src/errors.c \

OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF) -lftprintf -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_DIR) -I$(FT_PRINTF) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(FT_PRINTF)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re