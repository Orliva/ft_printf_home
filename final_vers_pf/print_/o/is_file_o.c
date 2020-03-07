/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _is_file_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:45:07 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 08:53:04 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/o.h"

unsigned	int	is_presition_o(t_param *param)
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

unsigned	int	is_width_o(t_param *param, t_flags *flag)
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

unsigned	int	is_sharp_o(t_param *param, t_flags *flag)
{
	unsigned	int i;

	i = 0;
	if (flag->sharp)
		i += write(param->fd, "0", 1);
	return (i);
}
