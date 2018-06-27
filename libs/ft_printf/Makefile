# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 10:53:51 by tle-huu-          #+#    #+#              #
#    Updated: 2018/03/12 17:18:31 by tle-huu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS += -g -Wall -Wextra -Werror
INCLUDES = includes
CC = gcc
NAME = libftprintf.a
LIBFT = ../libft/libft.a

SRCS = srcs/init.c
SRCS += srcs/parser.c
SRCS += srcs/ft_printf.c
SRCS += srcs/ft_print_specifier.c
SRCS += srcs/print_hex.c
SRCS += srcs/print_mhex.c
SRCS += srcs/print_string.c
SRCS += srcs/print_char.c
SRCS += srcs/print_obelus.c
SRCS += srcs/print_integer.c
SRCS += srcs/print_unsint.c
SRCS += srcs/print_bigunsint.c
SRCS += srcs/print_linteger.c
SRCS += srcs/print_pointer.c
SRCS += srcs/print_wstring.c
SRCS += srcs/print_oct.c
SRCS += srcs/handle_h.c
SRCS += srcs/handle_l.c
SRCS += srcs/handle_j.c
SRCS += srcs/handle_z.c
SRCS += srcs/handle_size.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf "\r\033[K\033[1;34m[PRINTF] \033[0;32mLinking...\033[0m"
	@cp $(LIBFT) $(NAME)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\r\033[K\033[1;34m[PRINTF] \033[0;32mDone!\033[0m\n"

$(LIBFT):
	@$(MAKE) -C ../libft
	@cp ../libft/includes/libft.h includes/

%.o: %.c $(LIBFT)
	@printf "\r\033[K[PRINTF] \033[0;32mBuilding $<\033[0m\n"
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@


clean:
	@$(MAKE) -C ../libft/ clean
	@rm -f $(OBJS)
	@printf "\033[1;34m[PRINTF] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@$(MAKE) -C ../libft/ fclean
	@rm -f $(NAME)
	@printf "\033[1;34m[PRINTF] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
	# **************************************************************************** #
