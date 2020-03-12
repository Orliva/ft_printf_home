/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:33:29 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:14:51 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/u.h"

static	unsigned	long	long	int	ft_pow_(unsigned long long int num,
		unsigned int count)
{
	while (count)
	{
		num *= 10;
		count--;
	}
	return (num);
}

static	unsigned	int					print_num_u(t_param *param,
		unsigned long long int var)
{
	unsigned	int	count;
	unsigned	int	i;
	char			tmp;

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
	if ((param->n_presit == 1 && param->presition != 0)
			|| param->n_presit == 0)
	{
		tmp = var + 48;
		i += write(param->fd, &tmp, 1);
	}
	return (i);
}

static	unsigned	int					final_print_u(t_param *param,
		t_flags *flag, unsigned long long int var)
{
	unsigned	int	i;

	i = 0;
	if (flag->minus)
	{
		i += is_presition_u(param);
		i += print_num_u(param, var);
		i += is_width_u(param, flag);
	}
	else
	{
		i += is_width_u(param, flag);
		i += is_presition_u(param);
		i += print_num_u(param, var);
	}
	return (i);
}

unsigned	int							init_num_u(unsigned long long int var,
		t_flags *flag, t_param *param)
{
	unsigned	int	i;

	i = 0;
	param->count = count_num_min(var, param);
	if (var == 0 && !param->n_presit)
		param->width = param->width > 0 ? param->width - 1 : 0;
	i += final_print_u(param, flag, var);
	return (i);
}
