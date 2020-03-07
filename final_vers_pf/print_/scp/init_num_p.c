/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:06:43 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:23:53 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/scp.h"

static	unsigned	int	right_pos(t_param *param, t_flags *flag)
{
	unsigned	int	i;

	i = 0;
	if (flag->zero)
	{
		i += is_sharp_p(param, flag);
		i += is_width_p(param, flag);
		i += is_presition_p(param);
	}
	else
	{
		i += is_width_p(param, flag);
		i += is_sharp_p(param, flag);
		i += is_presition_p(param);
	}
	return (i);
}

static	unsigned	int	final_print_p(t_param *param,
		t_flags *flag, unsigned long long int var)
{
	unsigned	int	i;

	i = 0;
	if (flag->minus)
	{
		i += is_sharp_p(param, flag);
		i += is_presition_p(param);
		i += print_num_p(param, var);
		i += is_width_p(param, flag);
	}
	else
	{
		i += right_pos(param, flag);
		i += print_num_p(param, var);
	}
	return (i);
}

unsigned	int			init_num_16_p(unsigned long long int var,
		t_flags *flag, t_param *param)
{
	unsigned	int	i;

	i = 0;
	if (var)
		param->count = count_num_min(var, param) - 1;
	else
	{
		param->count = 0;
		if ((param->n_presit && param->presition == 0) || param->n_presit == 0)
			param->width = param->width > 0 ? param->width - 1 : 0;
	}
	if (flag->sharp)
		if (param->width > 1)
			param->width -= 2;
	i += final_print_p(param, flag, var);
	return (i);
}
