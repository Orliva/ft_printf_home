/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _is_file_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:21:47 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 08:44:37 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/di.h"

unsigned	int	is_presition_di(t_param *param)
{
	unsigned	int	i;

	i = 0;
	while (param->presition > param->count)
	{
		i += write(param->fd, "0", 1);
		param->presition--;
		if (param->width > 0)
			param->width--;
	}
	return (i);
}

unsigned	int	is_width_di(t_param *param, t_flags *flag)
{
	char			tmp;
	unsigned	int	i;

	i = 0;
	tmp = flag->zero == 1 ? '0' : ' ';
	while (param->width > param->presition && param->width > param->count)
	{
		i += write(param->fd, &tmp, 1);
		param->width--;
	}
	return (i);
}

unsigned	int	is_sign_space_di(t_pr *pr, t_param *param, t_flags *flag)
{
	unsigned	int i;

	i = 0;
	if (flag->plus == 1 && pr->sign == '+')
	{
		i += write(param->fd, "+", 1);
		flag->plus = 0;
	}
	if (pr->sign == '-')
	{
		i += write(param->fd, "-", 1);
		pr->sign = 'N';
	}
	if (flag->space == 1)
	{
		i += write(param->fd, " ", 1);
		flag->space = 0;
	}
	return (i);
}
