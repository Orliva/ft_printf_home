/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oxXs_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:11:36 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:15:23 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	o_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
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

void	xx_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	if (choice_mod(param) == NONE_MODE)
		default_mod_xx(param, all_len, flag);
	if (choice_mod(param) == H)
		h_mod_xx(param, all_len, flag);
	if (choice_mod(param) == HH)
		hh_mod_xx(param, all_len, flag);
	if (choice_mod(param) == L_DOWN)
		l_mod_xx(param, all_len, flag);
	if (choice_mod(param) == LL_DOWN)
		ll_mod_xx(param, all_len, flag);
}

void	s_func(t_param *param, unsigned int *all_len, t_flags *flag)
{
	default_mod_s(param, all_len, flag);
}
