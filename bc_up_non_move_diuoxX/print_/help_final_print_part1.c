#include "../include/ft_printf.h"

void    _is_presition(char *print, t_param *param, t_flags *flag, unsigned int val)
{
        if (param->presition > 0 && (param->type == 'd' ||
        param->type == 'i' || param->type == 'o' ||
        param->type == 'x' || param->type == 'X' || param->type == 'p'))//////возможно для u(нужен тест)
                flag->zero = 0;
//	if (flag->sharp == 1 && (param->type == 'x' || param->type == 'X') && param->width >=2)
		
        while (param->presition > val)
        {
                print[--param->len] = '0';
		param->presition--;
		if (param->width > 0)
			param->width--;
        }
}

void    _is_width(t_pr *pr, t_param *param, t_flags *flag, unsigned int val)
{
        char tmp;

        tmp = flag->zero == 1 ? '0' : ' ';
	if (flag->sharp == 1 && (param->type == 'x' || param->type == 'X' || param->type == 'p') && param->width > 1 && flag->zero == 1)
		param->width -= 2;
//	if (flag->sharp == 1 && (param->type == 'x' || param->type == 'X') && param->width >= 2)
//		param->width -= 2;
	if (flag->sharp == 1 && param->type == 'o' && param->width > 0 && flag->minus == 0)
		param->width--;
	if (param->width > 0)
		param->width -= pr->dop_mem;
//	printf("width_is_width = %u\n",param->width); ////
//	if (flag->zero == 0)
//		param->width--;
	while (param->width > val)
	{
		pr->print[--param->len] = tmp;
		param->width--;
	}
//	printf("width_is_width = %u\n",param->width); ////
}

void    _is_sharp(char *print, t_param *param, t_flags *flag)
{
        if (flag->sharp == 1 && (param->type == 'x' || param->type == 'X' || param->type == 'p'))
        {
		if (param->width > 1)
			param->width -= 2;
                print[--param->len] = 'x';
                print[--param->len] = '0';
        }
        if (flag->sharp == 1 && param->type == 'o' && print[param->len] != '0')
	{
		if (param->width > 0)
			param->width--;
		print[--param->len] = '0';
	}
}

void    _is_sign_space(t_pr *pr, t_param *param, t_flags *flag)
{
        if (flag->plus == 1 && pr->sign == '+')//////при создании num указать sign
		{
//			printf("\nsharp = %d, zero = %d, minus = %d, plus = %d, space = %d\n", flag->sharp, flag->zero, flag->minus, flag->plus, flag->space);
//			write(1, &pr->sign, 1);
//			write(1, "WHAT?_1", 7);
			pr->print[--param->len] = '+';
			flag->plus = 0;
			param->width = param->width > 0 ? param->width - 1 : 0;
		}
        if (pr->sign == '-')
		{
///			write(1, "WHAT?_2", 7); ////
			pr->print[--param->len] = '-';
			pr->sign = 'N';
			param->width = param->width > 0 ? param->width - 1 : 0;
		}
        if (flag->space == 1)
		{
///			write(1, "WHAT?_3", 7); ///
			pr->print[--param->len] = ' ';
			flag->space = 0;
			param->width = param->width > 0 ? param->width - 1 : 0;
		}
}

void	upper_case_pf(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32; //////посчитать минус сколько
		i++;
	}
}
