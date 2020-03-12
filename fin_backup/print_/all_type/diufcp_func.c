/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diufcp_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:10:54 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 19:24:30 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

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

void	u_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (choice_mod(param) == NONE_MODE)
		default_mod_u(param, all_len, flag);
	if (choice_mod(param) == H)
		h_mod_u(param, all_len, flag);
	if (choice_mod(param) == HH)
		hh_mod_u(param, all_len, flag);
	if (choice_mod(param) == L_DOWN)
		l_mod_u(param, all_len, flag);
	if (choice_mod(param) == LL_DOWN)
		ll_mod_u(param, all_len, flag);
}

void	ff_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (choice_mod(param) == NONE_MODE)
		default_mod_f(param, all_len, flag);
	if (choice_mod(param) == L_UP)
		l_up_mod_f(param, all_len, flag);
	if (choice_mod(param) == L_DOWN)
		l_mod_f(param, all_len, flag);
}

void	c_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	default_mod_c(param, all_len, flag);
}

void	p_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	default_mod_p(param, all_len, flag);
}
