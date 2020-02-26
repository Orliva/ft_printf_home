/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type_is_spes_symb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:18:50 by lulee             #+#    #+#             */
/*   Updated: 2020/02/26 19:18:53 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	is_spesific_symb(t_param *param, unsigned int *all_len)
{
	char *tmp;

	tmp = param->dup_format;
	while (*tmp != '%' && *tmp) 
	{
		if (*tmp == 'd' || *tmp == 'i' || *tmp == 'u' || *tmp == 'o' ||
				*tmp == 'x' || *tmp == 'X' || *tmp == 'f' || *tmp == 'F'
				|| *tmp == 'c' || *tmp == 's' || *tmp == 'p')
			return (1);
		tmp++;
	}
	param->dup_format = tmp;
	(*all_len)++;
	write(param->fd, "%", 1);
	if (*param->dup_format)
		param->dup_format++;
	return (0);
}

void	is_type(t_param *param)
{
	if (*param->dup_format == 'd' || *param->dup_format == 'i' ||
			*param->dup_format == 'u' || *param->dup_format == 'o' ||
			*param->dup_format == 'x' || *param->dup_format == 'X' ||
			*param->dup_format == 'f' || *param->dup_format == 'F' ||
			*param->dup_format == 'c' || *param->dup_format == 'p' ||
			*param->dup_format == 's')
		param->type = *param->dup_format;
	if (param->presition == 0 && param->fF_presi != 1 &&
		(param->type == 'f' || param->type == 'F'))
		param->presition = 6;
	if (param->presition > 0 && param->type == 'c')
		param->presition = 0;
	param->dup_format++;
}
