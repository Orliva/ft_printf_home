#include "../ft_printf.h"

void	h_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	short int var;
	t_pr	pr;
	unsigned char len;

	len = 0;
	pr.sign = '+';
	if ((var = (short int)va_arg(param->arg, int)) < 0)
	{
		len++;
		pr.sign = '-';
		flag->plus = 0;
	}
	pr.print = mall_width(param, (len += count_num_pl((long long int)var)), flag);
	init_num_di(&pr, (long long int)var);
	final_print(&pr, param, all_len, flag);////another named func;
}

void	h_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned int var;
	t_pr	pr;

	var = (unsigned short int)va_arg(param->arg, unsigned int);
	pr.sign = '+';
	pr.print = mall_width(param, count_num_min((unsigned long long int)var), flag);
	init_num_ouxX(&pr, (unsigned long long int)var);
	final_print(&pr, param, all_len, flag);
}

void	hh_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	char var;
	t_pr	pr;
	unsigned int len;

	len = 0;
	pr.sign = '+';
	if ((var = (char)va_arg(param->arg, int)) < 0)
	{
		len++;
		pr.sign = '-';
		flag->plus = 0;
	}
	pr.print = mall_width(param, (len += count_num_min((long long int)var)), flag);
	init_num_di(&pr, (long long int)var);
	final_print(&pr, param, all_len, flag);
}

void	hh_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned char var;
	t_pr	pr;

	pr.sign = '+';
	var = (unsigned char)va_arg(param->arg, unsigned int);
	pr.print = mall_width(param, count_num_min((unsigned long long int)var), flag);
	init_num_ouxX(&pr, (unsigned long long int)var);
	final_print(&pr, param, all_len, flag);
}
/*
void	L_mod_fegEG(t_param *param, unsigned int *all_len, t_flags *flag)
{
	long double var;
	char *str_print;

	var = va_arg(param->arg, long double);
	str_print = mall_width(param,);
	flag_print();
}*/
