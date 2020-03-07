/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_ff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:19:59 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 19:20:01 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ff.h"

void			is_width_f(t_pr *pr, t_param *param,
		t_flags *flag, unsigned int val)
{
	char	tmp;

	tmp = flag->zero == 1 ? '0' : ' ';
	while (param->width > val)
	{
		pr->num[pr->i++] = tmp;
		param->width--;
	}
}

void			is_sign_space_f(t_pr *pr, t_param *param,
		t_flags *flag)
{
	param->len++;
	if (flag->plus && pr->sign == '+')
	{
		pr->num[pr->i++] = '+';
		flag->plus = 0;
	}
	if (pr->sign == '-')
	{
		pr->num[pr->i++] = '-';
		pr->sign = 'N';
	}
	if (flag->space)
	{
		pr->num[pr->i++] = ' ';
		flag->space = 0;
	}
}

static	int		dot(long double var, t_flags *flag, t_param *param)
{
	unsigned	int	val;

	if (flag->sharp)
		return (1);
	if (!param->presition)
		return (0);
	val = count_num_f(var);
	var /= ft_pow_lld((long double)1, val);
	while (val)
	{
		var = var * 10 - (int)(var * 10);
		val--;
	}
	if (var != (long double)0)
		return (1);
	return (0);
}

unsigned	int	val(t_param *param, t_flags *flag,
		long double var)
{
	if (param->width > (param->count = count_num_f(var)
				+ param->len + dot(var, flag, param)))
		return (param->count);
	return (param->width);
}

void			right_pos_f(t_pr *pr, t_param *param,
		t_flags *flag, unsigned int val_)
{
	if (flag->zero)
	{
		is_sign_space_f(pr, param, flag);
		is_width_f(pr, param, flag, val_);
	}
	else
	{
		is_width_f(pr, param, flag, val_);
		is_sign_space_f(pr, param, flag);
	}
}
