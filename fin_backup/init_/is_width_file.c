/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_width_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:19:05 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 08:32:14 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	pf_atoi_(t_param *param)
{
	int	n;

	n = 10;
	while (*param->dup_format &&
		*param->dup_format >= '0' && *param->dup_format <= '9')
	{
		param->width = (n * param->width) + (*param->dup_format - '0');
		param->dup_format++;
	}
}

void			is_width(t_param *param)
{
	param->width = 0;
	if (*param->dup_format >= '0' && *param->dup_format <= '9')
		pf_atoi_(param);
	while (*param->dup_format == '.' && *param->dup_format)
		param->dup_format++;
}
