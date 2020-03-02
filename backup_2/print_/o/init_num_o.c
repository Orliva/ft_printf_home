/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:41:21 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 23:02:27 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/o.h"

static	long long int ft_pow_(long long int num, unsigned int count)
{
	while (count)
	{
		num *= 8;
		count--;
	}
	return (num);
}

static	unsigned	int	print_num_o(t_param *param, long long int var)
{
	unsigned int i;
	char	tmp;
	unsigned	int	count;

	i = 0;
	count = 0;
	if (param->count > 0)
		count = param->count - 1;
	while (count)
	{
		tmp = (var / ft_pow_((long long int)1, count)) + 48;
		i += write(param->fd, &tmp, 1);
		var %= ft_pow_((long long int)1, count);
		count--;
	}
	if ((param->s_presit == 1 && param->presition != 0) || param->s_presit == 0)
	{
		tmp = (var / ft_pow_((long long int)1, count)) + 48;
		i += write(param->fd, &tmp, 1);
	}
	return (i);
}

static	unsigned	int	right_pos(t_param *param, t_flags *flag)
{
	unsigned	int	i;

	i = 0;
	if (flag->zero)
	{
		i += _is_sharp_o(param, flag);
		i += _is_width_o(param, flag);
		i += _is_presition_o(param);
	}
	else
	{
		i += _is_width_o(param, flag);
		i += _is_sharp_o(param, flag);
		i += _is_presition_o(param);
	}
	return (i);
}

static	unsigned	int	final_print_o(t_param *param, t_flags *flag, unsigned long long int var)
{
	unsigned	int	i;

	i = 0;
	if (flag->minus)
	{
		i += _is_sharp_o(param, flag);
		i += _is_presition_o(param);
		i += print_num_o(param, var);
		i += _is_width_o(param, flag);
	}
	else
	{
		i += right_pos(param, flag);
		i += print_num_o(param, var);
	}
	return (i);
}

unsigned int	init_num_8(unsigned long long int var, t_flags *flag, t_param *param)
{
	unsigned	int	i;

	i = 0;
	param->count = count_num_min(var, param);
	param->len = param->count;
	if (flag->sharp)
		param->len++;
	if (param->len < param->presition)
		param->len = param->presition;
	if (param->len < param->width)
		param->len = param->width;
	if (param->len == 0)
		param->len++;
	i += final_print_o(param, flag, var);
	return (i);
}
