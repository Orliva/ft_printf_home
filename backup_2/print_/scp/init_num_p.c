/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:41:21 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 22:42:58 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/scp.h"

static	unsigned	int	right_pos(t_param *param, t_flags *flag)
{
	unsigned	int	i;

	i = 0;
	if (flag->zero)
	{
		i += _is_sharp_p(param, flag);
		i += _is_width_p(param, flag);
		i += _is_presition_p(param);
	}
	else
	{
		i += _is_width_p(param, flag);
		i += _is_sharp_p(param, flag);
		i += _is_presition_p(param);
	}
	return (i);
}

static	unsigned	int	final_print_p(t_param *param, t_flags *flag, unsigned long long int var)
{
	unsigned	int	i;

	i = 0;
	if (flag->minus)
	{
		i += _is_sharp_p(param, flag);
		i += _is_presition_p(param);
		i += print_num_p(param, var);
		i += _is_width_p(param, flag);
	}
	else
	{
		i += right_pos(param, flag);
		i += print_num_p(param, var);
	}
	return (i);
}

unsigned int	init_num_16_p(unsigned long long int var, t_flags *flag, t_param *param)
{
	unsigned	int	i;

	i = 0;
	param->count = count_num_min(var, param);
	if (flag->sharp)
		if (param->width > 1)
			param->width -= 2;
	if (param->len == 0)///////под костыль
		param->len++;
	i += final_print_p(param, flag, var);
	return (i);
}
