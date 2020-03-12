NAME = libftprintf.a

C_FILE = ft_printf.c init_/flag_file.c init_/init_param.c init_/is_mod_file.c init_/is_presition_file.c init_/is_type_is_spes_symb.c init_/is_width_file.c init_/protect_seg.c print_/all_type/all_type_print.c print_/all_type/choice_mod.c print_/all_type/diufcp_func.c print_/all_type/help_func.c print_/all_type/oxxs_func.c print_/di/init_num_di.c print_/di/is_file_di.c print_/di/mod_di_file.c print_/di/print_num_di.c print_/o/init_num_o.c print_/o/is_file_o.c print_/o/mod_o_file.c print_/scp/init_num_c.c print_/scp/init_num_p.c print_/scp/init_num_s.c print_/scp/is_file_p.c print_/scp/mod_file.c print_/scp/print_num_p.c  print_/u/init_num_u.c print_/u/is_file_u.c print_/u/mod_u_file.c print_/xX/init_num_xx.c print_/xX/is_file_xx.c print_/xX/mod_xx_file.c print_/xX/mod_xx_file.c print_/xX/print_num_xx.c print_/f/help_f.c print_/f/init_num_ff.c print_/f/is_file_ff.c print_/f/mod_ff_file.c

O_FILE = ft_printf.o flag_file.o init_param.o is_mod_file.o is_presition_file.o is_type_is_spes_symb.o is_width_file.o protect_seg.o all_type_print.o choice_mod.o diufcp_func.o help_func.o oxxs_func.o init_num_di.o is_file_di.o mod_di_file.o print_num_di.o init_num_o.o is_file_o.o mod_o_file.o init_num_c.o init_num_p.o init_num_s.o is_file_p.o mod_file.o print_num_p.o  init_num_u.o is_file_u.o mod_u_file.o init_num_xx.o is_file_xx.o mod_xx_file.o mod_xx_file.o print_num_xx.o help_f.o init_num_ff.o is_file_ff.o mod_ff_file.o

GCC_FLAGS = -Wall -Wextra -Werror

$(NAME):./include/ft_printf.h %.c
	gcc $(GCC_FLAGS) -c $(C_FILE) -I ./include
	ar rc $(NAME) $(O_FILE)
	ranlib $(NAME)

all:$(NAME)

clean:
	rm -rf $(O_FILE)

fclean: clean
	rm -rf $(NAME)

re:fclean all
