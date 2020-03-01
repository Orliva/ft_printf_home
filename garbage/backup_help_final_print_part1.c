#include "../include/ft_printf.h"

unsigned	int	_is_presition_di(t_param *param, t_flags *flag)
{
	unsigned	int	i;

	i = 0;
	while (param->presition > param->count)////////тут не param->len, количество цифр var
	{
		i += write(param->fd, "0", 1);
		param->presition--;
		if (param->width > 0)
			param->width--;
		param->len--;
	}
//	printf("presition___param->len = %u\n",param->len);
	return (i);
}

unsigned	int	_is_width_di(t_pr *pr, t_param *param, t_flags *flag)
{
	char tmp;
	unsigned	int	i;

	i = 0;
	tmp = flag->zero == 1 ? '0' : ' ';
//	if (flag->zero == 1)
//	{
//		if (flag->plus || flag->space || pr->sign == '-')
//			if (param->width > 0)
//				param->width--;
//		if (flag->sharp && (param->type == 'x' || param->type == 'X' || param->type == 'p'))
//			if (param->width > 1)
//				param->width -= 2;
//		if (flag->sharp && param->type == 'o')
//			if (param->width > 0)
//				param->width--;
//	}
//	printf("width = %u\n", param->width);
	if ((flag->plus == 1 || flag->space == 1 || pr->sign == '-') && param->width > 0)
		param->width--;
//	printf("width = %u\n", param->width);
	/*if (flag->sharp == 1 && (param->type == 'x' || param->type == 'X' || param->type == 'p')
			&& param->width > 1 && flag->zero == 1)
		param->width -= 2;*/
//	if (flag->sharp == 1 && (param->type == 'x' || param->type == 'X') && param->width >= 2)
//		param->width -= 2;
	/*if (flag->sharp == 1 && param->type == 'o' && param->width > 0 && flag->minus == 0)
		param->width--;*/
	if (param->width > 0)
		param->width -= pr->dop_mem;
//	printf("width_is_width = %u\n",param->width); ////
//	if (flag->zero == 0)
//		param->width--;
	while (param->width > param->presition && param->width > param->count)
	{
		i += write(param->fd, &tmp, 1);
		param->width--;
		param->len--;
	}
//	printf("param->len = %u\n",param->len);
	return (i);
//	printf("width_is_width = %u\n",param->width); ////
}

unsigned	int	_is_sharp_di(t_param *param, t_flags *flag)
{
	unsigned	int i;

	i = 0;
	if (flag->sharp == 1 && (param->type == 'x' || param->type == 'X' || param->type == 'p'))
	{
		if (param->width > 1)
			param->width -= 2;
		i += write(param->fd, "0", 1);
		i += write(param->fd, "x", 1);
		param->len -= 2;
	}
	if (flag->sharp == 1 && param->type == 'o')
	{
		if (param->width > 0)
			param->width--;
		i += write(param->fd, "0", 1);
		param->len--;
	}
	return (i);
}

unsigned	int	_is_sign_space_di(t_pr *pr, t_param *param, t_flags *flag)
{
	unsigned	int i;

	i = 0;
	if (flag->plus == 1 && pr->sign == '+')//////при создании num указать sign
	{
//			printf("\nsharp = %d, zero = %d, minus = %d, plus = %d, space = %d\n", flag->sharp, flag->zero, flag->minus, flag->plus, flag->space);
//			write(1, &pr->sign, 1);
//			write(1, "WHAT?_1", 7);
		i += write(param->fd, "+", 1);
		flag->plus = 0;
//		printf("start %u\n", param->width);
		param->width = param->width > 0 ? param->width - 1 : 0;
//		printf("end %u\n", param->width);
//		param->len--;
	}
	if (pr->sign == '-')
	{
///			write(1, "WHAT?_2", 7); ////
		i += write(param->fd, "-", 1);
		pr->sign = 'N';
		param->width = param->width > 0 ? param->width - 1 : 0;
//		param->len--;
	}
	if (flag->space == 1)
	{
///			write(1, "WHAT?_3", 7); ///
		i += write(param->fd, " ", 1);
		flag->space = 0;
		param->width = param->width > 0 ? param->width - 1 : 0;
//		param->len--;
	}
	return (i);
}

void	upper_case_pdf(char *str)
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
