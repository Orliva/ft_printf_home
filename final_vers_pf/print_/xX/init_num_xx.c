/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:39:07 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:12:44 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/xx.h"

static	unsigned	int	right_pos(t_param *param, t_flags *flag)
{
	unsigned	int	i;

	i = 0;
	if (flag->zero)
	{
		i += is_sharp_xx(param, flag);
		i += is_width_xx(param, flag);
		i += is_presition_xx(param);
	}
	else
	{
		i += is_width_xx(param, flag);
		i += is_sharp_xx(param, flag);
		i += is_presition_xx(param);
	}
	return (i);
}

static	unsigned	int	final_print_xx(t_param *param, t_flags *flag,
		unsigned long long int var)
{
	unsigned	int	i;

	i = 0;
	if (flag->minus)
	{
		i += is_sharp_xx(param, flag);
		i += is_presition_xx(param);
		i += print_num_xx(param, var);
		i += is_width_xx(param, flag);
	}
	else
	{
		i += right_pos(param, flag);
		i += print_num_xx(param, var);
	}
	return (i);
}

unsigned	int			init_num_16_xx(unsigned long long int var,
		t_flags *flag, t_param *param)
{
	unsigned	int	i;

	i = 0;
	param->count = count_num_min(var, param);
	if (var == 0)
		flag->sharp = 0;
	if (var == 0 && !param->n_presit)
		param->width = param->width > 0 ? param->width - 1 : 0;
	if (flag->sharp)
		if (param->width > 1)
			param->width -= 2;
	i += final_print_xx(param, flag, var);
	return (i);
}
