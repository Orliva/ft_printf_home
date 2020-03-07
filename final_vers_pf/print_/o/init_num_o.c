/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:44:58 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 08:58:29 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/o.h"

static	long	long	int	ft_pow_(unsigned long long int num,
		unsigned int count)
{
	while (count)
	{
		num *= 8;
		count--;
	}
	return (num);
}

static	unsigned	int		print_num_o(t_param *param,
		unsigned long long int var)
{
	unsigned	int	i;
	char			tmp;
	unsigned	int	count;

	i = 0;
	count = 0;
	if (param->count > 0)
		count = param->count - 1;
	while (count)
	{
		tmp = (var / ft_pow_((unsigned long long int)1, count)) + 48;
		i += write(param->fd, &tmp, 1);
		var %= ft_pow_((unsigned long long int)1, count);
		count--;
	}
	if ((param->n_presit == 1 && param->presition != 0) || param->n_presit == 0)
	{
		tmp = var + 48;
		i += write(param->fd, &tmp, 1);
	}
	return (i);
}

static	unsigned	int		right_pos(t_param *param, t_flags *flag)
{
	unsigned	int	i;

	i = 0;
	if (flag->zero)
	{
		i += is_sharp_o(param, flag);
		i += is_width_o(param, flag);
		i += is_presition_o(param);
	}
	else
	{
		i += is_width_o(param, flag);
		i += is_sharp_o(param, flag);
		i += is_presition_o(param);
	}
	return (i);
}

static	unsigned	int		final_print_o(t_param *param, t_flags *flag,
		unsigned long long int var)
{
	unsigned	int	i;

	i = 0;
	if (flag->minus)
	{
		i += is_sharp_o(param, flag);
		i += is_presition_o(param);
		i += print_num_o(param, var);
		i += is_width_o(param, flag);
	}
	else
	{
		i += right_pos(param, flag);
		i += print_num_o(param, var);
	}
	return (i);
}

unsigned	int				init_num_8(unsigned long long int var,
		t_flags *flag, t_param *param)
{
	unsigned	int	i;

	i = 0;
	param->count = count_num_min(var, param);
	if (flag->sharp)
	{
		param->presition = param->presition > 0 ? param->presition - 1 : 0;
		param->n_presit = 0;
	}
	if (flag->sharp && var == 0)
		flag->sharp = 0;
	if (flag->sharp)
		if (param->width > 0)
			param->width--;
	if (!param->n_presit && var == 0)
		param->width = param->width > 0 ? param->width - 1 : 0;
	i += final_print_o(param, flag, var);
	return (i);
}
