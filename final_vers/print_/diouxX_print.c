#include "../ft_printf.h"

void	init_flag(t_param *param, t_flags *flag)
{
	int i;

	i = -1;
	printf("param->flag = %s\n", param->flag);
	while (param->flag[++i])
	{
		if (param->flag[i] == '-')
			flag->minus = 1;
		if (param->flag[i] == '+')
			flag->plus = 1;
		if (param->flag[i] == '#')
			flag->sharp = 1;
		if (param->flag[i] == '0')
			flag->zero = 1;
		if (param->flag[i] == ' ')
			flag->space = 1;
	}
	if (flag->plus == 1)
		flag->space = 0;
	if ((flag->minus == 1 || param->presition != 0))
		flag->zero = 0;
//	free(&param->flag);/////возможно будет ошибка при компиляции!
}

void	diouxX_print(t_param *param, unsigned int *all_len)
{
	t_flags	flag;
	void	(*ptr_ints_f)(t_param *, unsigned int *, t_flags *) = NULL;

	init_flag(param, &flag);/////Проверить правильно ли инициализируется флаг
	if (param->type == 'd' || param->type == 'i')
		ptr_ints_f = di_func;
/*	if (param->type == 'u')
		ptr_ints_f = u_func;
	if (param->type == 'o')
		ptr_ints_f = o_func;
	if (param->type == 'x' || param->type == 'X')
		ptr_ints_f = xX_func;*/
	ptr_ints_f(param, all_len, &flag);
	/*if (param->mod[0] != '\0')
	{
		if (compare("h", H) == 0)
			atoi_short_diouxX(param, &flag);//va_start(param->arg, short int);
		if (compare("hh", HH) == 0)
			atoi_char_diouxX(param, &flag);
		if (compare("l", L_DOWN) == 0)
			atoi_long_diouxX(param, &flag);
		if (compare("ll", LL_DOWN) == 0)
			atoi_llong_diouxX(param, &flag);
		if (compare("L", L_UP) == 0)
			atoi_llong_diouxX(param, &flag);
	}
	else
		atoi_int_diouxX(param, &flag);*/
}
