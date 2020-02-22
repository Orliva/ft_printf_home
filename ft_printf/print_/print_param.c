#include "../ft_printf.h"

void	print_param(t_param *param, unsigned int *all_len)
{
	void	(*ptr_print)(t_param *, unsigned int *);

	if (param->type == 'd' || param->type == 'i' || param->type == 'u'
		|| param->type == 'o' || param->type == 'x' || param->type == 'X')
		ptr_print = diouxX_print;
	/*if (param->type == 'f' || param->type == 'F' || param->type == 'e'
		|| param->type == 'E' || param->type == 'g' || param->type == 'G'
		|| param->type == 'a' || param->type == 'A')
		ptr_print = fegaFEGA_print;
	if (param->type == 'c' || param->type == 's' || param->type == 'S')
		ptr_print = csS_print;*/
	ptr_print(param, all_len);
}
