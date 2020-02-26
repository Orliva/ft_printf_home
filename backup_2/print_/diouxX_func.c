/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:27:01 by lulee             #+#    #+#             */
/*   Updated: 2020/02/26 20:44:54 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	di_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (choice_mod(param) == NONE_MODE)
		default_mod_di(param, all_len, flag);
	if (choice_mod(param) == H)
		h_mod_di(param, all_len, flag);
	if (choice_mod(param) == HH)
		hh_mod_di(param, all_len, flag);
	if (choice_mod(param) == L_DOWN)
		l_mod_di(param, all_len, flag);
	if (choice_mod(param) == LL_DOWN)
		ll_mod_di(param, all_len, flag);
}

void	ouxX_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (choice_mod(param) == NONE_MODE)
		default_mod_ouxX(param, all_len, flag);
	if (choice_mod(param) == H)
		h_mod_ouxX(param, all_len, flag);
	if (choice_mod(param) == HH)
		hh_mod_ouxX(param, all_len, flag);
	if (choice_mod(param) == L_DOWN)
		l_mod_ouxX(param, all_len, flag);
	if (choice_mod(param) == LL_DOWN)
		ll_mod_ouxX(param, all_len, flag);
}

void	fF_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (choice_mod(param) == NONE_MODE)
		default_mod_fF(param, all_len, flag);
//	if (choice_mod(param) == L_UP)
//		L_mod_fF(param, all_len, flag);
}

void	c_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (param->type == 'c')
		if (choice_mod(param) == NONE_MODE)
			default_mod_c(param, all_len, flag);
	if (param->type == 's')
		if (choice_mod(param) == NONE_MODE)
			default_mod_s(param, all_len, flag);
}

void	p_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (choice_mod(param) == NONE_MODE)
		default_mod_p(param, all_len, flag);
}
