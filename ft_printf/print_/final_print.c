#include "../ft_printf.h"

///////в num записано число реверсом!!
void	right_pos(t_pr *pr, t_param *param, t_flags *flag)
{
	while (*pr->num)
	{
		pr->print[--param->len] = *pr->num--;//////MAY BE ERROR!!! num--
		param->presition--;
		param->width--;
	}
	_is_presition(pr->print, param, flag);
	_is_width(pr->print, param, flag);
	_is_sharp(pr->print, param, flag);
	_is_sign_space(pr, param, flag);
}

void	left_pos(t_pr *pr, t_param *param, t_flags *flag)
{
	_is_width(pr->print, param, flag);
	while (*pr->num)
	{
		pr->print[--param->len] = *pr->num--;//////MAY BE ERROR!!! num--
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
		left_pos(pr, param, flag);
	else
		right_pos(pr, param, flag);
	if (param->type == 'X')
		upper_case_pf(pr->print);
	ft_strlen_fd(pr->print, param, all_len);
}
