C_FILE = main.c ft_printf.c init_/flag_file.c init_/init_param.c init_/is_mod_file.c init_/is_presition_file.c init_/is_type_is_spes_symb.c init_/is_width_file.c print_/choice_mod.c print_/diouxX_func.c print_/diouxX_print.c print_/final_print.c print_/help_final_print_part1.c print_/help_func.c print_/help_func_part2.c print_/init_num.c print_/mall_width.c print_/mod_file_part1.c print_/mod_file_part2.c print_/mod_file_part3.c print_/print_param.c

O_FILE = main.o ft_printf.o flag_file.o init_param.o is_mod_file.o is_presition_file.o is_type_is_spes_symb.o is_width_file.o choice_mod.o diouxX_func.o diouxX_print.o final_print.o help_final_print_part1.o help_func.o help_func_part2.o init_num.o mall_width.o mod_file_part1.o mod_file_part2.o mod_file_part3.o print_param.o

GCC_FLAGS = -Wall -Wextra -Werror

all:
	gcc -c $(C_FILE)
	gcc $(GCC_FLAGS) $(O_FILE)

clear:
	rm $(O_FILE)

fclear:	clear

re:fclear all
