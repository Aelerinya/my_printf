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
	src/my_putnbr_base.c \
	src/my_putptr.c
OBJ = $(notdir $(SRC:.c=.o))
TEST = tests/test_conversion_specifier.c
TEST_OBJ = $(notdir $(SRC:.c=.o)) $(notdir $(TEST:.c=.o))
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

tests_run:
	@gcc -c $(SRC) $(TEST) --coverage -Iinclude
	@gcc -o tests_run $(TEST_OBJ) --coverage -lcriterion
	@./tests_run
	@rm tests_run $(TEST_OBJ)

re: fclean all

.PHONY: all clean fclean re
