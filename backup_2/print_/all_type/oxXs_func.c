/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:27:01 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 21:23:55 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	o_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
//	printf("param->mod %s\n", param->mod);
	if (choice_mod(param) == NONE_MODE)
		default_mod_o(param, all_len, flag);
	if (choice_mod(param) == H)
		h_mod_o(param, all_len, flag);
	if (choice_mod(param) == HH)
		hh_mod_o(param, all_len, flag);
	if (choice_mod(param) == L_DOWN)
		l_mod_o(param, all_len, flag);
	if (choice_mod(param) == LL_DOWN)
		ll_mod_o(param, all_len, flag);
}

void	xX_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (choice_mod(param) == NONE_MODE)
		default_mod_xX(param, all_len, flag);
	if (choice_mod(param) == H)
		h_mod_xX(param, all_len, flag);
	if (choice_mod(param) == HH)
		hh_mod_xX(param, all_len, flag);
	if (choice_mod(param) == L_DOWN)
		l_mod_xX(param, all_len, flag);
	if (choice_mod(param) == LL_DOWN)
		ll_mod_xX(param, all_len, flag);
}

void	s_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	default_mod_s(param, all_len, flag);
}
