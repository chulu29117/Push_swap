# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clu <clu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 09:56:36 by clu               #+#    #+#              #
#    Updated: 2024/12/20 21:03:52 by clu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SOURCES = 	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_i.c \
			ft_puthex.c ft_puthex_low.c ft_puthex_up.c ft_putptr.c \
			ft_format_check.c
		  
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Linking library $(NAME)"
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
