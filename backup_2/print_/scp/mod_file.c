/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_file_part3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:39:25 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 22:32:29 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/scp.h"

void	default_mod_p(t_param *param, unsigned	int	*all_len, t_flags *flag)
{
	void	*var;
	t_pr	pr;
	char	tmp;

	var = va_arg(param->arg, void *);
	flag->sharp = 1;
	if (var)
		*all_len += init_num_16_p(&pr, (unsigned long long int)var, flag, param);
	else
	{
		tmp = flag->zero == 1 ? '0' : ' ';
		while (param->width > 3 && tmp == ' ' && flag->minus == 0)
		{
			*all_len += write(param->fd, &tmp, 1);
			param->width--;
		}
		while (param->width > 3 && (tmp == '0' || flag->minus == 1))
		{
			*all_len += write(param->fd, &tmp, 1);
			param->width--;
		}
	}
}

void	default_mod_c(t_param *param, unsigned int *all_len, t_flags *flag)
{
	unsigned char var;

	var = (unsigned char)va_arg(param->arg, unsigned int);
	init_num_c(flag, param, all_len, var);
}

void	default_mod_s(t_param *param, unsigned int *all_len, t_flags *flag)
{
	char	*var;

	var = va_arg(param->arg, char *);
	init_num_s(flag, param, all_len, var);
	(*all_len)++;
}
