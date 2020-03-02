/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_file_part3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:39:25 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 22:48:48 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/xX.h"

void	default_mod_xX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	int	var;
	t_pr			pr;

	var = va_arg(param->arg, unsigned int);
	*all_len += init_num_16_xX(&pr, (unsigned long long int)var, flag, param);
}
void	h_mod_xX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	short	int	var;
	t_pr					pr;

	var = (unsigned short int)va_arg(param->arg, unsigned int);
	*all_len += init_num_16_xX(&pr, (unsigned long long int)var, flag, param);
}
void	hh_mod_xX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	char	var;
	t_pr				pr;

	var = (unsigned char)va_arg(param->arg, unsigned int);
	*all_len += init_num_16_xX(&pr, (unsigned long long int)var, flag, param);
}
void	l_mod_xX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned long int var;
	t_pr	pr;

	var = va_arg(param->arg, unsigned long int);
	*all_len += init_num_16_xX(&pr, (unsigned long long int)var, flag, param);
}
void	ll_mod_xX(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned long long int var;
	t_pr	pr;

	var = va_arg(param->arg, unsigned long long int);
	*all_len += init_num_16_xX(&pr, (unsigned long long int)var, flag, param);
}
