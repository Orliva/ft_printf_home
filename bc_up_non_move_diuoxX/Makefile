NAME = libftprintf.a

C_FILE = ft_printf.c print_/init_num_c.c print_/init_num_s.c print_/final_print_fF.c print_/help_final_print_fF.c print_/mall_width_fF.c print_/init_num_fF.c init_/flag_file.c init_/init_param.c init_/is_mod_file.c init_/is_presition_file.c init_/is_type_is_spes_symb.c init_/is_width_file.c print_/choice_mod.c print_/diouxX_func.c print_/diouxX_print.c print_/final_print.c print_/help_final_print_part1.c print_/help_func.c print_/help_func_part2.c print_/init_num.c print_/mall_width.c print_/mod_file_part1.c print_/mod_file_part2.c print_/mod_file_part3.c

O_FILE = ft_printf.o init_num_c.o init_num_s.o final_print_fF.o help_final_print_fF.o mall_width_fF.o init_num_fF.o flag_file.o init_param.o is_mod_file.o is_presition_file.o is_type_is_spes_symb.o is_width_file.o choice_mod.o diouxX_func.o diouxX_print.o final_print.o help_final_print_part1.o help_func.o help_func_part2.o init_num.o mall_width.o mod_file_part1.o mod_file_part2.o mod_file_part3.o

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
