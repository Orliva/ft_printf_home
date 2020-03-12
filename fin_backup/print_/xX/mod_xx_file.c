/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_xX_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:39:51 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:14:15 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/xx.h"

void	default_mod_xx(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	int	var;

	var = va_arg(param->arg, unsigned int);
	if (var != 0 && param->presition == 0)
		param->presition++;
	*all_len += init_num_16_xx((unsigned long long int)var, flag, param);
}

void	h_mod_xx(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	short	int	var;

	var = (unsigned short int)va_arg(param->arg, unsigned int);
	if (var != 0 && param->presition == 0)
		param->presition++;
	*all_len += init_num_16_xx((unsigned long long int)var, flag, param);
}

void	hh_mod_xx(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	char	var;

	var = (unsigned char)va_arg(param->arg, unsigned int);
	if (var != 0 && param->presition == 0)
		param->presition++;
	*all_len += init_num_16_xx((unsigned long long int)var, flag, param);
}

void	l_mod_xx(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned long int var;

	var = va_arg(param->arg, unsigned long int);
	if (var != 0 && param->presition == 0)
		param->presition++;
	*all_len += init_num_16_xx((unsigned long long int)var, flag, param);
}

void	ll_mod_xx(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned long long int var;

	var = va_arg(param->arg, unsigned long long int);
	if (var != 0 && param->presition == 0)
		param->presition++;
	*all_len += init_num_16_xx((unsigned long long int)var, flag, param);
}
