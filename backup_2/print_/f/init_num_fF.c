#include "inc/fF.h"

static	unsigned	int	part_doub(t_param *param, double *var)
{
	unsigned	int	i;
	char	tmp;

	i = 0;
	*var *= 10;
	while (param->presition)
	{
//		printf("var = %f\n", *var);
		if ((int)(*var * 10) == 0)
			i += write(param->fd, "0", 1);
		else
		{
		//	tmp = (char)(*var * 10 + 48);
			tmp = ((int)*var != 9) ? (int)(*var + 0.01) : (int)*var;
			*var = (*var - tmp) * 10;
			tmp += 48;
			//*var = *var * 10 - (int)(*var * 10);
			i += write(param->fd, &tmp, 1);
		}
//		printf("var = %f\n\n", *var);
		param->presition--;
	}
	return (i);
}

static	unsigned	int	part_int(t_param *param, double *var, unsigned int val)
{
	unsigned	int	i;
//	double	int_part;
	char	tmp;

	i = 0;
//	printf("val = %u\n", val);
//	int_part = (long long int)var;
//	printf("var = %f\n", *var);
	*var /= ft_pow_lld((double)1, val);
//	printf("var = %f\n", *var);
	while (val)
	{
		tmp = (char)(*var * 10 + 48);
//		printf("tmp = %d\n", tmp);
//		printf("var = %f\n", *var);
		*var = *var * 10 - (int)(*var * 10);
//		printf("var = %f\n", *var);
//		tmp_int += 48;
		i += write(param->fd, &tmp, 1);
		val--;
	}
//	var = int_part;
	return (i);
}

static	unsigned	int	print_num_fF(t_param *param, t_flags *flag, double var)
{
	unsigned	int	i;

	i = 0;
	i += part_int(param, &var, count_num_f(var));
	if (flag->sharp)
	{
		i += write(param->fd, ".", 1);
	}
	else
	{
		if (var != (double)0)
			i += write(param->fd, ".", 1);
	}
	i += part_doub(param, &var);
	return (i);
}

unsigned	int	init_num_fF(t_pr *pr, t_param *param, t_flags *flag, double num)
{
	unsigned	int	i;
	///////////дописать ширину
	i = 0;
	if (pr->sign == '-')
		i += write(param->fd, "-", 1);
	i += print_num_fF(param, flag, num);
	return (i);
}
