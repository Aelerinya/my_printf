##
## EPITECH PROJECT, 2018
## my_printf
## File description:
## Makefile for the my_printf lib
##

SRC =	src/my_printf.c \
	src/my_putchar.c \
	src/my_put_nbr.c \
	src/my_putstr.c \
	src/my_showstr.c \
	src/my_putnbr_base.c
OBJ = $(notdir $(SRC:.c=.o))
NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc libmy.a $(OBJ)

$(OBJ):
	gcc -c $(SRC) -Iinclude/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
