#include "../ft_printf.h"

void	l_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	long int var;
	t_pr	pr;
	unsigned int len;

	len = 0;
	pr.sign = '+';
	if ((var = va_arg(param->arg, long int)) < 0)
	{
		len++;
		pr.sign = '-';
		flag->plus = 0;
	}
	pr.print = mall_width(param, (len += count_num_pl((long long int)var)), flag);
	init_num_di(&pr, (long long int)var);
	final_print(&pr, param, all_len, flag);
}

void	l_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned long int var;
	t_pr	pr;

	var = va_arg(param->arg, unsigned long int);
	pr.sign = '+';
	pr.print = mall_width(param, count_num_min((unsigned long long int)var), flag);
	init_num_ouxX(&pr, (unsigned long long int)var);
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
		len++;
		pr.sign = '-';
		flag->plus = 0;
	}
	pr.print = mall_width(param, (len += count_num_pl((long long int)var)), flag);
	init_num_di(&pr, (long long int)var);
	final_print(&pr, param, all_len, flag);
}

void	ll_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned long long int var;
	t_pr	pr;

	pr.sign = '+';
	var = va_arg(param->arg, unsigned long long int);
	pr.print = mall_width(param, count_num_min((unsigned long long int)var), flag);
	init_num_ouxX(&pr, (unsigned long long int)var);
	final_print(&pr, param, all_len, flag);
}
/*
void	default_mod_c(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned char var;
	char symb;
	///////
	//etc
	//////
}*/
