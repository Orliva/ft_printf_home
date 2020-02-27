#include "../include/ft_printf.h"

void    _is_presition_fF(char *print, t_param *param, unsigned int val)
{
        while (param->presition > val)
        {
                print[--param->len] = '0';
		param->presition--;
		if (param->width > 0)
			param->width--;
        }
}

void    _is_width_fF(t_pr *pr, t_param *param, t_flags *flag, unsigned int val)
{
        char tmp;

        tmp = flag->zero == 1 ? '0' : ' ';
//	printf("width_is_width = %u\n",param->width); ////
	while (param->width > val)
	{
		pr->print[--param->len] = tmp;
		param->width--;
	}
//	printf("width_is_width = %u\n",param->width); ////
}

void    _is_sign_space_fF(t_pr *pr, t_param *param, t_flags *flag)
{
	if (flag->plus == 1 && pr->sign == '+')
	{
		pr->print[--param->len] = '+';
		flag->plus = 0;
		param->width = param->width > 0 ? param->width - 1 : 0;
	}
	if (pr->sign == '-')
	{
		pr->print[--param->len] = '-';
		pr->sign = 'N';
		param->width = param->width > 0 ? param->width - 1 : 0;
	}
	if (flag->space == 1)
	{
		pr->print[--param->len] = ' ';
		flag->space = 0;
		param->width = param->width > 0 ? param->width - 1 : 0;
	}
}
