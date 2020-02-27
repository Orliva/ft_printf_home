/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type_is_spes_symb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:18:50 by lulee             #+#    #+#             */
/*   Updated: 2020/02/27 17:17:19 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	unsigned	int	part_proc_print(t_param *param, char tmp)
{
	unsigned	int	len;

	len = 0;
	if (param->width > 0)
		param->width--;
	while (param->width)
	{
		len += write(param->fd, &tmp, 1);
		if (param->width > 0)
			param->width--;
	}
	return (len);
}

static	unsigned	int	proc_print(t_param *param, t_flags *flag)
{
	char	tmp;
	unsigned	int	len;

	len = 0;
	if (flag->minus == 1)
		flag->zero = 0;
	tmp = flag->zero == 1 ? '0' : ' ';
	if (flag->minus == 1)
	{
		write(param->fd, "%", 1);
		len += part_proc_print(param, tmp);
	}
	else
	{
		len += part_proc_print(param, tmp);
		write(param->fd, "%", 1);
	}
	return (len);
}

int	is_spesific_symb(t_param *param, unsigned int *all_len)
{
	char *tmp;
	t_flags flag;

	tmp = param->dup_format;
	while (*tmp != '%' && *tmp) 
	{
		if (*tmp == 'd' || *tmp == 'i' || *tmp == 'u' || *tmp == 'o' ||
				*tmp == 'x' || *tmp == 'X' || *tmp == 'f' || *tmp == 'F'
				|| *tmp == 'c' || *tmp == 's' || *tmp == 'p')
			return (1);
		tmp++;
	}
	is_flag(param);
	init_flag(param, &flag);
	is_width(param);
	is_presition(param);
	*all_len += proc_print(param, &flag);
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
