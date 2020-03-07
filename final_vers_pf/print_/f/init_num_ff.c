/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_ff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:20:08 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 19:20:10 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ff.h"

static	void	part_doub(t_pr *pr, t_param *param, long double *var)
{
	char	tmp;

	*var *= 10;
	while (param->presition)
	{
		if ((int)(*var * 10) == 0)
			pr->num[pr->i++] = '0';
		else
		{
			tmp = ((int)*var != 9) ? (int)(*var + 0.01) : (int)*var;
			*var = (*var - tmp) * 10;
			tmp += 48;
			pr->num[pr->i++] = tmp;
		}
		param->presition--;
	}
}

static	void	part_int(t_pr *pr, t_param *param,
		long double *var, unsigned int val)
{
	char	tmp;

	*var /= ft_pow_lld((long double)1, val);
	param->len++;
	while (val)
	{
		tmp = (char)(*var * 10 + 48);
		*var = *var * 10 - (int)(*var * 10);
		pr->num[pr->i++] = tmp;
		val--;
	}
}

static	void	print_num_f(t_pr *pr, t_param *param,
		t_flags *flag, long double var)
{
	part_int(pr, param, &var, count_num_f(var));
	if (flag->sharp && param->presition)
		pr->num[pr->i++] = '.';
	else
	{
		if (var != (long double)0 && param->presition)
			pr->num[pr->i++] = '.';
	}
	part_doub(pr, param, &var);
}

static	void	final_print_f(t_pr *pr, t_param *param,
		t_flags *flag, long double num)
{
	unsigned	int	val_;

	val_ = val(param, flag, num);
	if (flag->minus)
	{
		is_sign_space_f(pr, param, flag);
		print_num_f(pr, param, flag, num);
		is_width_f(pr, param, flag, val_);
	}
	else
	{
		right_pos_f(pr, param, flag, val_);
		print_num_f(pr, param, flag, num);
	}
}

void			init_num_f(t_pr *pr, t_param *param,
		t_flags *flag, long double num)
{
	param->len = param->presition;
	pr->i = 0;
	if (num < 0)
	{
		num = -num;
	}
	if (flag->plus || flag->space || pr->sign == '-')
		param->width = param->width > 0 ? param->width - 1 : 0;
	if (!(pr->num = (char *)malloc(sizeof(char) *
					((param->width > val(param, flag, num) ? param->width
					: param->count) + 1))))
		ft_error_exit();
	final_print_f(pr, param, flag, num);
}
