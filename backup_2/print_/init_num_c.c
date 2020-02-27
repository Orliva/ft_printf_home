/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:45:57 by lulee             #+#    #+#             */
/*   Updated: 2020/02/26 18:46:03 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	left_pos_c(t_param *param, unsigned int *all_len, unsigned char num)
{
	while (param->width > 1)
	{
		write(param->fd, " ", 1);
		param->width--;
		(*all_len)++;
	}
	write(param->fd, &num, 1);
	(*all_len)++;
}

static	void	right_pos_c(t_param *param, unsigned int *all_len, unsigned char num)
{
	write(param->fd, &num, 1);
	(*all_len)++;
	while (param->width > 1)
	{
		write(param->fd, " ", 1);
		param->width--;
		(*all_len)++;
	}
}


void			init_num_c(t_flags *flag, t_param *param, unsigned int *all_len, unsigned char num)
{
	if (flag->minus == 0)
		left_pos_c(param, all_len, num);
	else
		right_pos_c(param, all_len, num);
}
