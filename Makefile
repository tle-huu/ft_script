# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/11 20:33:21 by tle-huu-          #+#    #+#              #
#    Updated: 2018/04/22 11:28:05 by tle-huu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_script

CFLAGS += -Wall -Werror -Wextra
INCLUDES = includes/
HEADERS = $(INCLUDES)*

SRCS += srcs/main.c
SRCS += srcs/utils.c
SRCS += srcs/parser.c
SRCS += srcs/set_term.c
SRCS += srcs/ft_script.c
SRCS += srcs/messages.c
SRCS += srcs/signal.c
SRCS += srcs/pty_functions.c
SRCS += srcs/fork.c




OBJS = $(SRCS:.c=.o)

LIBFT = libftprintf.a

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(HEADERS)
	@printf "\r\033[K\033[1;33m[$(NAME)] \033[0;32mLinking...\033[0m\n"
	@echo "tle-huu-" > author
	@gcc $(CFLAGS) -I$(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "\r\033[K\033[1;33m[$(NAME)] \033[0;32mDone !\033[0m\n"

$(LIBFT):
	@make -C libs/
	@cp libs/ft_printf/includes/libft.h $(INCLUDES)
	@cp libs/ft_printf/libftprintf.a .

%.o: %.c
	@printf "\r\033[K\033[1;33m[$(NAME)] \033[0;32mBuilding $<\033[0m\n"
	gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C libs/ clean
	@rm -f $(OBJS)
	@printf "\033[1;32m[$(NAME)] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@$(MAKE) -C libs/ fclean
	@rm -f $(NAME)
	@rm -f libftprintf.a
	@printf "\033[1;32m[$(NAME)] \033[1;31mCleaned all!\033[0m\n"

re: fclean all
