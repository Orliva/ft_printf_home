/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _is_file_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:39:27 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:12:57 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/xx.h"

unsigned	int	is_presition_xx(t_param *param)
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

unsigned	int	is_width_xx(t_param *param, t_flags *flag)
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

unsigned	int	is_sharp_xx(t_param *param, t_flags *flag)
{
	unsigned	int i;

	i = 0;
	if (flag->sharp)
	{
		i += write(param->fd, "0", 1);
		if (param->type == 'x')
			i += write(param->fd, "x", 1);
		else
			i += write(param->fd, "X", 1);
	}
	return (i);
}
