/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mod_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:16:47 by lulee             #+#    #+#             */
/*   Updated: 2020/02/26 17:17:41 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int	part_is_mod(t_param *param)
{
	int	len;

	len = 0;
	while (*param->dup_format == 'h' || *param->dup_format == 'l' ||
		*param->dup_format == 'L')
	{
		len++;
		param->dup_format++;
	}
	return (len);
}

void	is_mod(t_param *param)
{
	int	len;

	if (!(param->mod = (char *)malloc(sizeof(char) * ((len = part_is_mod(param)) + 1))))
		ft_error_exit();
	param->mod[len] = '\0';
	len--;
	while (len >= 0)
	{
		param->dup_format--;
		param->mod[len] = *param->dup_format;
		len--;
	}
	part_is_mod(param);
}
