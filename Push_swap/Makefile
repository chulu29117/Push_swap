# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clu <clu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 20:33:14 by clu               #+#    #+#              #
#    Updated: 2025/01/15 12:58:35 by clu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME = push_swap

# Comiler and Flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = Libft
FT_PRINTF = ft_printf

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(FT_PRINTF)/libftprintf.a

# Source files
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

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@echo "Compiling $(NAME)"
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF) -lftprintf -o $(NAME)
	@echo "Done"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_DIR) -I$(FT_PRINTF) -c $< -o $@

$(LIBFT):
	@echo "Compiling Libft..."
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@echo "Compiling ft_printf..."
	@make -C $(FT_PRINTF)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF) clean
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned up object files"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF) fclean
	@rm -f $(NAME)
	@echo "Cleaned up everything"

re: fclean all
	@echo "Remade everything"

# Phony targets
.PHONY: all clean fclean re