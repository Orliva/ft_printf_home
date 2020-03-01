#include "../include/ft_printf.h"

static	double	ft_pow_lld(double num, unsigned int count)
{
	while (count)
	{
		num *= 10;
		count--;
	}
	return (num);
}

static	unsigned	int	part_print_num_f(t_param *param, double &var, unsigned int val)
{
	unsigned	int	i;
	double	int_part;
	int	tmp_int;

	i = 0;
	int_part = (long long int)var;
	int_part /= ft_pow_lld((double)1, count);
	while (val)
	{
		tmp_int = (int)(int_part * 10);
		int_part = (int_part * 10) - (double)tmp_int;
		i += write(param->fd, &tmp_int, 1);
		val--;
	}
	*var = int_part;
	return (i);
}

static	unsigned	int	print_num_fF(t_param *param, t_flags *flag, double var)
{
	unsigned	int	count;
	double	int_part;
	int	tmp_int;

	i += part_print_num_f(param, &var, count_num_pl((long long int)var));
	if (flag->sharp)
		i += write(param->fd, ".", 1);
	else
		if (var != (double)0)
			i += write(param->fd, ".", 1);
	i += part_print_num_f(param, &var, param->presition);
	return (i);
}

unsigned	int	init_num_fF(t_pr *pr, t_param *param, t_flags *flag, double num)
{
	unsigned	int	i;
	///////////дописать ширину

	if (pr->sign == '-')
		i += write(param->fd, "-", 1);
	i += print_num_fF(param, flag, num);
	return (i);
}
