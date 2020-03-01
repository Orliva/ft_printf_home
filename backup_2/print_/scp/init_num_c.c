/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:45:57 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 22:29:27 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scp.h"

static	void	left_pos_c(t_param *param, unsigned int *all_len, unsigned char num)
{
	while (param->width > 1)
	{
		*all_len += write(param->fd, " ", 1);
		param->width--;
	}
	*all_len += write(param->fd, &num, 1);
}

static	void	right_pos_c(t_param *param, unsigned int *all_len, unsigned char num)
{
	*all_len += write(param->fd, &num, 1);
	while (param->width > 1)
	{
		*all_len += write(param->fd, " ", 1);
		param->width--;
	}
}


void			init_num_c(t_flags *flag, t_param *param, unsigned int *all_len, unsigned char num)
{
	if (flag->minus == 0)
		left_pos_c(param, all_len, num);
	else
		right_pos_c(param, all_len, num);
}
