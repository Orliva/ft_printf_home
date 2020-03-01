/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_file_part3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:39:25 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 23:15:57 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	default_mod_fF(t_param *param, unsigned int *all_len, t_flags *flag)
{
	double var;
	t_pr	pr;

	pr.sign = '+';
	if ((var = va_arg(param->arg, double)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
	*all_len += init_num_fF(&pr, param, flag, var);
}
/*
void	l_mod_fF(t_param *param, unsigned int *all_len, t_flags *flag)
{
	double var;
	t_pr	pr;

	pr.sign = '+';
	if ((var = va_arg(param->arg, double)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
//		init_num_fF_(&pr, param->presition, var > 0 ? var : -var);
	(*all_len)++;/////удалить
//		mall_width_fF(param, ft_strlen(pr.num), flag, &pr);
//		final_print_fF(&pr, param, all_len, flag);////
}

void	L_mod_fF(t_param *param, unsigned int *all_len, t_flags *flag)
{
	long	double	var;
	t_pr			pr;

	pr.sign = '+';
	if ((var = va_arg(param->arg, long double)) < 0)
	{
		pr.sign = '-';
		flag->plus = 0;
		flag->space = 0;
	}
//		init_num_fF_(&pr, param->presition, var > 0 ? var : -var);
	(*all_len)++;/////удалить
//		mall_width_fF(param, ft_strlen(pr.num), flag, &pr);
//		final_print_fF(&pr, param, all_len, flag);////
}*/
