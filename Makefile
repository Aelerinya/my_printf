##
## EPITECH PROJECT, 2018
## my_printf
## File description:
## Makefile for the my_printf lib
##

SRC =	src/my_printf.c \
	src/my_putchar.c \
	src/my_nbr_to_str.c \
	src/my_putstr.c \
	src/my_showstr.c \
	src/my_nbr_base.c \
	src/my_putptr.c \
	src/my_charstr.c \
	src/my_strcpy.c \
	src/integer_conversion.c
OBJ = $(notdir $(SRC:.c=.o))
TEST = 	tests/test_conversion_specifier.c \
	tests/test_length_modifier.c
TEST_OBJ = $(notdir $(SRC:.c=.o)) $(notdir $(TEST:.c=.o))
NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc libmy.a $(OBJ)

$(OBJ):
	gcc -c $(SRC) -Iinclude/ -Wall -Wextra -pedantic

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

tests_run:
	@gcc -c $(SRC) $(TEST) --coverage -Iinclude -Wall -Wextra -pedantic
	@gcc -o tests_run $(TEST_OBJ) --coverage -lcriterion
	@./tests_run
	@rm tests_run $(TEST_OBJ)

re: fclean all

.PHONY: all clean fclean re tests_run
