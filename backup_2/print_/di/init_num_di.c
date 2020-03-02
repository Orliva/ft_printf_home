/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:41:21 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 23:25:25 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/di.h"

static	long	long	int	ft_pow_(long long int num, unsigned int count)
{
	while (count)
	{
		num *= 10;
		count--;
	}
	return (num);
}

static	unsigned	int		print_num_di(t_param *param, long long int var)
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

static	unsigned	int		right_pos(t_pr *pr, t_param *param, t_flags *flag)
{
	unsigned	int	i;

	i = 0;
	if (flag->zero)
	{
		i += _is_sign_space_di(pr, param, flag);
		i += _is_width_di(pr, param, flag);
		i += _is_presition_di(param);
	}
	else
	{
		i += _is_width_di(pr, param, flag);
		i += _is_sign_space_di(pr, param, flag);
		i += _is_presition_di(param);
	}
	return (i);
}

static	unsigned	int		final_print_di(t_pr *pr, t_param *param, t_flags *flag, long long int var)
{
	unsigned	int	i;

	i = 0;
	if (flag->minus)
	{
		i += _is_sign_space_di(pr, param, flag);
		i += _is_presition_di(param);
		i += print_num_di(param, var);
		i += _is_width_di(pr, param, flag);
	}
	else
	{
		i += right_pos(pr, param, flag);
		i += print_num_di(param, var);
	}
	return (i);
}

unsigned	int				init_num_di(t_pr *pr, long long int var, t_flags *flag, t_param *param)
{
	unsigned	int	i;

	i = 0;
	param->count = count_num_pl(var);
	param->len = param->count;
	if (param->len < param->presition)
		param->len = param->presition;
	if (flag->space == 1 || flag->plus == 1 || pr->sign == '-')
		param->len++;
	if (param->len < param->width)
		param->len = param->width;
	if (param->len == 0)
		param->len++;
	i += final_print_di(pr, param, flag, var);
	return (i);
}
