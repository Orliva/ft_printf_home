#include "../ft_printf.h"

///////в num записано число реверсом!!
void	right_pos(t_pr *pr, t_param *param, t_flags *flag)
{
	while (*pr->num)
	{
//		write(1, pr->num, 1);
		pr->print[--param->len] = *pr->num++;
		if (param->presition != 0)
			param->presition--;
		if (param->width != 0)
			param->width--;
	}
	printf("width = %u", param->width);
	_is_presition(pr->print, param, flag, (unsigned int)0);
	if (flag->zero == 0 && param->width > 0)
		_is_sign_space(pr,param, flag);
	if (flag->zero == 1 && (flag->plus == 1 || pr->sign == '-' || flag->space == 1) && param->width > 0)
		param->width--;
	printf("width = %u\n", param->width);
	_is_width(pr->print, param, flag, (unsigned int)0);
	_is_sharp(pr->print, param, flag);
	_is_sign_space(pr, param, flag);
}

void	left_pos(t_pr *pr, t_param *param, t_flags *flag)
{
	unsigned int i;

	if ((flag->plus == 1 || pr->sign == '-' || flag->space == 1) && param->width > 0)
		param->width--;
	i = ft_strlen(pr->num);
	if (param->presition < i)
		param->presition = i;
	printf("i = %u\n", i);
	printf("param->width = %u\n", param->width);
	if (param->width > param->presition)
		_is_width(pr->print, param, flag, param->presition);
	while (*pr->num)
	{
		pr->print[--param->len] = *pr->num++;
		if (param->presition != 0)
			param->presition--;
		if (param->presition != 0)
			param->width--;
	}
	_is_presition(pr->print, param, flag, 0);
	_is_sharp(pr->print, param, flag);
	_is_sign_space(pr, param, flag);
}

void	final_print(t_pr *pr, t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (flag->minus == 1)
		left_pos(pr, param, flag);
	else
		right_pos(pr, param, flag);
	if (param->type == 'X')
		upper_case_pf(pr->print);
	ft_putstr_fd(pr->print, param, all_len);/////ПЕЧАТЬ ТУТ!!! ft_strlen(str);
//	free(pr->print);
}
