#include "../include/ft_printf.h"

void	l_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	long int var;
	t_pr	pr;
	unsigned int len;

	len = 0;
	pr.sign = '+';
	if ((var = va_arg(param->arg, long int)) < 0)
	{
//		len++;
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	pr.print = mall_width(param, (len += count_num_pl((long long int)var)), flag, &pr);
	init_num_di(&pr, (long long int)var);
	final_print(&pr, param, all_len, flag);
}

void	l_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned long int var;
	t_pr	pr;

	var = va_arg(param->arg, unsigned long int);
	pr.sign = '+';
	pr.print = mall_width(param, count_num_min((unsigned long long int)var, param), flag, &pr);
	if (param->type == 'u')
		init_num_u(&pr, (unsigned long long int)var);
	if (param->type == 'x' || param->type == 'X')
		init_num_16(&pr, (unsigned long long int)var);
	if (param->type == 'o')
		init_num_8(&pr, (unsigned long long int)var);
	final_print(&pr, param, all_len, flag);
}

void	ll_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	long long int var;
	t_pr	pr;
	unsigned int len;

	len = 0;
	pr.sign = '+';
	if ((var = va_arg(param->arg, long long int)) < 0)
	{
//		len++;
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	pr.print = mall_width(param, (len += count_num_pl((long long int)var)), flag, &pr);
	init_num_di(&pr, (long long int)var);
	final_print(&pr, param, all_len, flag);
}

void	ll_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned long long int var;
	t_pr	pr;

	pr.sign = '+';
	var = va_arg(param->arg, unsigned long long int);
	pr.print = mall_width(param, count_num_min((unsigned long long int)var, param), flag, &pr);
	if (param->type == 'u')
		init_num_u(&pr, (unsigned long long int)var);
	if (param->type == 'x' || param->type == 'X')
		init_num_16(&pr, (unsigned long long int)var);
	if (param->type == 'o')
		init_num_8(&pr, (unsigned long long int)var);
	final_print(&pr, param, all_len, flag);
}

void	default_mod_p(t_param *param, unsigned int *all_len, t_flags *flag)
{
	void	*var;
	t_pr	pr;
	char	tmp;

	pr.sign = '+';
	var = va_arg(param->arg, void *);
	flag->plus = 0;
	flag->space = 0;
	flag->sharp = 1;
	if (var)
	{
		pr.print = mall_width(param, count_num_min((unsigned long long int)var, param), flag, &pr);
		init_num_16(&pr, (unsigned long long int)var);
		final_print(&pr, param, all_len, flag);
	}
	else
	{
		tmp = flag->zero == 1 ? '0' : ' ';
		while (param->width > 3 && tmp == ' ' && flag->minus == 0)
		{
			write(param->fd, &tmp, 1);
			(*all_len)++;
			param->width--;
		}
		*all_len += write(param->fd, "0x0", 3);
		while (param->width > 3 && (tmp == '0' || flag->minus == 1))
		{
			write(param->fd, &tmp, 1);
			(*all_len)++;
			param->width--;
		}
	}
}
