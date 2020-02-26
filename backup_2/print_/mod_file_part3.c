/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_file_part3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:39:25 by lulee             #+#    #+#             */
/*   Updated: 2020/02/26 22:04:32 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	default_mod_di(t_param *param, unsigned int *all_len, t_flags *flag)
{
	int var;
	t_pr	pr;
	unsigned int len;

	len = 0;
	pr.sign = '+';
	if ((var = va_arg(param->arg, int)) < 0)
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

void	default_mod_ouxX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned int var;
	t_pr	pr;

	pr.sign = '+';
	var = va_arg(param->arg, unsigned int);
	pr.print = mall_width(param, count_num_min((unsigned long long int)var, param), flag, &pr);
	if (param->type == 'u')
		init_num_u(&pr, (unsigned long long int)var);
	if (param->type == 'x' || param->type == 'X')
		init_num_16(&pr, (unsigned long long int)var);
	if (param->type == 'o')
		init_num_8(&pr, (unsigned long long int)var);
//	write(1, &pr.num, 2);
	final_print(&pr, param, all_len, flag);
}

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
	if (param->presition < 18)
	{
		init_num_fF_(&pr, param->presition, var > 0 ? var : -var);
		mall_width_fF(param, ft_strlen(pr.num), flag, &pr);
		final_print_fF(&pr, param, all_len, flag);////
	}
}

void	default_mod_c(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned char var;

	var = (unsigned char)va_arg(param->arg, unsigned int);
	init_num_c(flag, param, all_len, var);
}

void	default_mod_s(t_param *param, unsigned int *all_len, t_flags *flag)
{
	char	*var;
//	char	tmp;

	var = va_arg(param->arg, char *);
	if (var)
		init_num_s(flag, param, all_len, var);
//	else
//	{
//		tmp = flag->zero == 1 ? '0' : ' ';
//		while (param->width
}
