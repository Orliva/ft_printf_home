/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:08:18 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:21:41 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/scp.h"

void	default_mod_p(t_param *param, unsigned int *all_len, t_flags *flag)
{
	void	*var;

	var = va_arg(param->arg, void *);
	flag->sharp = 1;
	*all_len += init_num_16_p((unsigned long long int)var, flag, param);
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
}
