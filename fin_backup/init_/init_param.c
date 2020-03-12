/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:12:32 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 11:22:39 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		init_param(t_param *param, unsigned int *all_len)
{
	param->dup_format++;
	if (*param->dup_format && is_spesific_symb(param, all_len) == 1)
	{
		is_flag(param);
		is_width(param);
		is_presition(param);
		is_mod(param);
		is_type(param);
		return (1);
	}
	return (0);
}
