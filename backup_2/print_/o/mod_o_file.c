/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_file_part3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:39:25 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 23:03:41 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o.h"

void	default_mod_o(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	int	var;

	var = va_arg(param->arg, unsigned int);
	*all_len += init_num_8((unsigned long long int)var, flag, param);
}
void	h_mod_o(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	short	int	var;

	var = (unsigned short int)va_arg(param->arg, unsigned int);
	*all_len += init_num_8((unsigned long long int)var, flag, param);
}
void	hh_mod_o(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned	char	var;

	var = (unsigned char)va_arg(param->arg, unsigned int);
	*all_len += init_num_8((unsigned long long int)var, flag, param);
}
void	l_mod_o(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned long int var;

	var = va_arg(param->arg, unsigned long int);
	*all_len += init_num_8((unsigned long long int)var, flag, param);
}
void	ll_mod_o(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned long long int var;

	var = va_arg(param->arg, unsigned long long int);
	*all_len += init_num_8((unsigned long long int)var, flag, param);
}
