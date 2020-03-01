#include "../include/ft_printf.h"

///////в num записано число реверсом!!
void	right_pos_fF(t_pr *pr, t_param *param, t_flags *flag)
{	
//	printf("width = %u", param->width); ////
	if (is_dot(pr) == 0 && flag->sharp == 1)
	{
		_is_presition_fF(pr->print, param, (unsigned int)0);
		pr->print[--param->len] = '.';
	}
	while (*pr->num)
	{
		pr->print[--param->len] = *pr->num++;
//		if (param->presition != 0)
//			param->presition--;
		if (param->width != 0)
			param->width--;
	}
//	printf("width = %u", param->width); ////
//	_is_presition(pr->print, param, flag, (unsigned int)0);
	if (flag->zero == 0 && param->width > 0)
		_is_sign_space_fF(pr,param, flag);
	if (flag->zero == 1 && (flag->plus == 1 || pr->sign == '-' || flag->space == 1) && param->width > 0)
		param->width--;
////	printf("width = %u\n", param->width); ////
	_is_width_fF(pr, param, flag, (unsigned int)0);
	_is_sign_space_fF(pr, param, flag);
}

void	left_pos_fF(t_pr *pr, t_param *param, t_flags *flag)
{
	unsigned int i;

	if ((flag->plus == 1 || pr->sign == '-' || flag->space == 1) && param->width > 0)
		param->width--;
	i = ft_strlen(pr->num);
///	printf("i = %u\n", i); ////
///	printf("param->width = %u\n", param->width); ////
	if (param->width > i)
		_is_width_fF(pr, param, flag, i);
	if (is_dot(pr) == 0 && flag->sharp == 1)
	{
		_is_presition_fF(pr->print, param, (unsigned int)0);
		pr->print[--param->len] = '.';
	}
	while (*pr->num)
	{
		pr->print[--param->len] = *pr->num++;
		if (param->width > 0)
			param->width--;
	}
////	printf("param->width = %u\n", param->width); ////
	_is_sign_space(pr, param, flag);
}

void	final_print_fF(t_pr *pr, t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (flag->minus == 1)
	{
		flag->zero = 0;
		left_pos(pr, param, flag);
	}
	else
		right_pos(pr, param, flag);
	ft_putstr_fd(pr->print, param, all_len);/////ПЕЧАТЬ ТУТ!!!
//	free(pr->print);
}
