
NAME = libft.a

CC = gcc
CFLAGS += -Wall -Wextra -Werror

SRCS +=	srcs/ft_atoi.c
SRCS += srcs/ft_bzero.c
SRCS += srcs/ft_isalpha.c
SRCS += srcs/ft_isdigit.c
SRCS += srcs/ft_isalnum.c
SRCS += srcs/ft_isascii.c
SRCS += srcs/ft_isprint.c
SRCS += srcs/ft_itoa.c
SRCS += srcs/ft_itoa_base.c
SRCS += srcs/ft_lstadd.c
SRCS += srcs/ft_lstdel.c
SRCS += srcs/ft_lstdelone.c
SRCS += srcs/ft_lstiter.c
SRCS += srcs/ft_lstlength.c
SRCS += srcs/ft_lstmap.c
SRCS += srcs/ft_lstnew.c
SRCS += srcs/ft_lstsortstring.c
SRCS += srcs/ft_lstutils.c
SRCS += srcs/ft_memalloc.c
SRCS += srcs/ft_memccpy.c
SRCS += srcs/ft_memchr.c
SRCS += srcs/ft_memcmp.c
SRCS += srcs/ft_memcpy.c
SRCS += srcs/ft_memdel.c
SRCS += srcs/ft_memmove.c
SRCS += srcs/ft_memset.c
SRCS += srcs/ft_putchar.c
SRCS += srcs/ft_putnchar.c
SRCS += srcs/ft_putchar_fd.c
SRCS += srcs/ft_putendl.c
SRCS += srcs/ft_putendl_fd.c
SRCS += srcs/ft_putnbr.c
SRCS += srcs/ft_putnbr_fd.c
SRCS += srcs/ft_putstr.c
SRCS += srcs/ft_putnstr.c
SRCS += srcs/ft_putstr_fd.c
SRCS += srcs/ft_putnwstr.c
SRCS += srcs/ft_sort_int_tab.c
SRCS += srcs/ft_sort_string_tab.c
SRCS += srcs/ft_strlen.c
SRCS += srcs/ft_strdup.c
SRCS += srcs/ft_strcpy.c
SRCS += srcs/ft_strncpy.c
SRCS += srcs/ft_strcat.c
SRCS += srcs/ft_strncat.c
SRCS += srcs/ft_strlcat.c
SRCS += srcs/ft_strchr.c
SRCS += srcs/ft_strsearch.c
SRCS += srcs/ft_strrchr.c
SRCS += srcs/ft_strstr.c
SRCS += srcs/ft_strnstr.c
SRCS += srcs/ft_strcmp.c
SRCS += srcs/ft_strncmp.c
SRCS += srcs/ft_toupper.c
SRCS += srcs/ft_tolower.c
SRCS += srcs/ft_strnew.c
SRCS += srcs/ft_strdel.c
SRCS += srcs/ft_strclr.c
SRCS += srcs/ft_striter.c
SRCS += srcs/ft_striteri.c
SRCS += srcs/ft_strmap.c
SRCS += srcs/ft_strmapi.c
SRCS += srcs/ft_strequ.c
SRCS += srcs/ft_strnequ.c
SRCS += srcs/ft_strsub.c
SRCS += srcs/ft_strjoin.c
SRCS += srcs/ft_strtrim.c
SRCS += srcs/ft_strsplit.c
SRCS += srcs/ft_tolower_str.c
SRCS += srcs/ft_power.c
SRCS += srcs/ft_minimax.c
SRCS += srcs/ft_nblen.c
SRCS += srcs/ft_wstrlen.c
SRCS += srcs/get_next_line.c

INC = includes/

OBJ = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@printf "\r\033[32m>>>   Building lib $(NAME)...   <<<\033[0m"
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\r\033[33m>>>   $(NAME) build !   <<<\033[0m"

%.o : %.c $(INC)/libft.h
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	@printf "\033[1;33m[LIBFT] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[1;33m[LIBFT] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
