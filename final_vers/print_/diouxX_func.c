#include "../ft_printf.h"


void	di_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (choice_mod(param) == NONE_MODE)
		default_mod_di(param, all_len, flag);
	if (choice_mod(param) == H)
		h_mod_di(param, all_len, flag);
	if (choice_mod(param) == HH)
		hh_mod_di(param, all_len, flag);
	if (choice_mod(param) == L_DOWN)
		l_mod_di(param, all_len, flag);
	if (choice_mod(param) == LL_DOWN)
		ll_mod_di(param, all_len, flag);

/////////////////////////////////////////////////////////////////
	/*if (var >= 0 && (flag->space == 1 || flag->plus == 1))
		len++;
	if (len <= param->width)
	{
		if (!(print_str = (char *)malloc((sizeof(char)) * (param->width + 1))))
			ft_error_exit();
	}
	else
		if (!(print_str = (char *)malloc((sizeof(char)) * (len + 1))))
			ft_error_exit();
	print_di_func();*/
/////////////////////////////////////////////////////////////////
}