/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_presition_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:13:04 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 08:29:28 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	pf_atoi(t_param *param)
{
	int	n;

	n = 10;
	while (*param->dup_format >= '0' && *param->dup_format <= '9')
	{
		param->n_presit = 1;
		param->presition = (param->presition * n) + (*param->dup_format - '0');
		param->dup_format++;
	}
}

void			is_presition(t_param *param)
{
	param->n_presit = 0;
	if (*(param->dup_format - 1) == '.')
		param->n_presit = 1;
	param->presition = 0;
	if (*param->dup_format >= '0' && *param->dup_format <= '9')
		pf_atoi(param);
}
