/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ff_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:19:50 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 19:19:52 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	default_mod_f(t_param *param, unsigned int *all_len, t_flags *flag)
{
	double	var;
	t_pr	pr;

	pr.sign = '+';
	if (param->presition > 0)
		flag->sharp = 1;
	if ((var = va_arg(param->arg, double)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	init_num_f(&pr, param, flag, (long double)var);
	ft_putstr_fd(pr.num, param, all_len);
}

void	l_mod_f(t_param *param, unsigned int *all_len, t_flags *flag)
{
	double	var;
	t_pr	pr;

	pr.sign = '+';
	if (param->presition > 0)
		flag->sharp = 1;
	if ((var = va_arg(param->arg, double)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	init_num_f(&pr, param, flag, (long double)var);
	ft_putstr_fd(pr.num, param, all_len);
}

void	l_up_mod_f(t_param *param, unsigned int *all_len, t_flags *flag)
{
	long	double	var;
	t_pr			pr;

	pr.sign = '+';
	if (param->presition > 0)
		flag->sharp = 1;
	if ((var = va_arg(param->arg, long double)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	init_num_f(&pr, param, flag, var);
	ft_putstr_fd(pr.num, param, all_len);
}
