/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_presition_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:16:04 by lulee             #+#    #+#             */
/*   Updated: 2020/02/26 19:34:57 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	pf_atoi(t_param *param)
{
	int	n;

	n = 10;
	param->fF_presi = 0;
	while (*param->dup_format >= '0' && *param->dup_format <= '9')
	{
		param->fF_presi = 1;
		param->s_presit = 1;
		param->presition = (param->presition * n) + (*param->dup_format - '0');
		param->dup_format++;
	}
}
void	is_presition(t_param *param)
{
	param->presition = 0;
	param->s_presit = 0;
	if (*param->dup_format >= '0' && *param->dup_format <= '9')
		pf_atoi(param);
}
