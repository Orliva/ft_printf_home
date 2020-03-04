NAME = libftprintf.a

C_FILE = ft_printf.c init_/*.c print_/all_type/*.c print_/di/*.c print_/o/*.c print_/scp/*.c print_/u/*.c print_/xX/*.c print_/f/*.c

O_FILE = *.o

GCC_FLAGS = -Wall -Wextra -Werror

$(NAME):./include/ft_printf.h
	gcc $(GCC_FLAGS) -c $(C_FILE) -I ./include
	ar rc $(NAME) $(O_FILE)
	ranlib $(NAME)

all:$(NAME)

clean:
	rm -rf $(O_FILE)

fclean: clean
	rm -rf $(NAME)

re:fclean all
