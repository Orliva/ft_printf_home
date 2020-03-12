/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_di_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:14:16 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 08:48:39 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/di.h"

void	default_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	int		var;
	t_pr	pr;

	pr.sign = '+';
	if ((var = va_arg(param->arg, int)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	if (var != 0 && param->presition == 0)
		param->presition++;
	*all_len += init_num_di(&pr, (long long int)var, flag, param);
}

void	h_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	short	int	var;
	t_pr		pr;

	pr.dop_mem = 0;
	pr.sign = '+';
	if ((var = (short int)va_arg(param->arg, int)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	if (var != 0 && param->presition == 0)
		param->presition++;
	*all_len += init_num_di(&pr, (long long int)var, flag, param);
}

void	hh_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	char	var;
	t_pr	pr;

	pr.sign = '+';
	pr.dop_mem = 0;
	if ((var = (char)va_arg(param->arg, int)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	if (var != 0 && param->presition == 0)
		param->presition++;
	*all_len += init_num_di(&pr, (long long int)var, flag, param);
}

void	l_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	long	int		var;
	t_pr			pr;

	pr.sign = '+';
	if ((var = va_arg(param->arg, long int)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	if (var != 0 && param->presition == 0)
		param->presition++;
	*all_len += init_num_di(&pr, (long long int)var, flag, param);
}

void	ll_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	long long int	var;
	t_pr			pr;

	pr.sign = '+';
	if ((var = va_arg(param->arg, long long int)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	if (var != 0 && param->presition == 0)
		param->presition++;
	*all_len += init_num_di(&pr, (long long int)var, flag, param);
}
