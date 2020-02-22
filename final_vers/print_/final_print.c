#include "../ft_printf.h"

///////в num записано число реверсом!!
void	right_pos(t_pr *pr, t_param *param, t_flags *flag)
{
//	write(1, "Start right\n", 12);
	while (*pr->num)
	{
//		printf("param->len = %d", param->len);
		pr->print[--param->len] = 48 + *pr->num++;//////MAY BE ERROR!!! num--
//		write(1, &pr->print[0], 4);
//		write(1, "\nFUCK",5);
		if (param->presition != 0)
			param->presition--;
		if (param->width != 0)
			param->width--;
//		pr->num++;
	}
	_is_presition(pr->print, param, flag);
	_is_width(pr->print, param, flag);
	_is_sharp(pr->print, param, flag);
	_is_sign_space(pr, param, flag);
//	write(1, "END_FUCK", 9);
}

void	left_pos(t_pr *pr, t_param *param, t_flags *flag)
{
	_is_width(pr->print, param, flag);
	while (*pr->num)
	{
		pr->print[--param->len] = 48 + *pr->num++;//////MAY BE ERROR!!! num--
		param->presition--;
		param->width--;
	}
	_is_presition(pr->print, param, flag);
	_is_sharp(pr->print, param, flag);
	_is_sign_space(pr, param, flag);
}
		
void	final_print(t_pr *pr, t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (flag->minus == 1)
	{
//		write(1, "LEFT", 5);
		left_pos(pr, param, flag);
	}
	else
	{
//		write(1, "RIGHT", 5);
		right_pos(pr, param, flag);
	}
	if (param->type == 'X')
		upper_case_pf(pr->print);
	ft_strlen_fd(pr->print, param, all_len);/////ПЕЧАТЬ ТУТ!!! ft_strlen(str);
}
