/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_u_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:43:59 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 22:56:47 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/u.h"

void	default_mod_u(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	int	var;

	var = va_arg(param->arg, unsigned int);
	*all_len += init_num_u((unsigned long long int)var, flag, param);
}

void	h_mod_u(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned int var;

	var = (unsigned short int)va_arg(param->arg, unsigned int);
	*all_len += init_num_u((unsigned long long int)var, flag, param);
}

void	hh_mod_u(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned char var;

	var = (unsigned char)va_arg(param->arg, unsigned int);
	*all_len += init_num_u((unsigned long long int)var, flag, param);
}

void	l_mod_u(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	int	var;

	var = va_arg(param->arg, unsigned long int);
	*all_len += init_num_u((unsigned long long int)var, flag, param);
}

void	ll_mod_u(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	int	var;

	var = va_arg(param->arg, unsigned long long int);
	*all_len += init_num_u((unsigned long long int)var, flag, param);
}
