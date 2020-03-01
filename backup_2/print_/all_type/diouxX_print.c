/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:22:48 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 23:15:27 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	flag_reset(t_flags *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->sharp = 0;
}

void	init_flag(t_param *param, t_flags *flag)
{
	int i;

	i = -1;
	while (param->flag[++i])
	{
		if (param->flag[i] == '-')
			flag->minus = 1;
		if (param->flag[i] == '+')
			flag->plus = 1;
		if (param->flag[i] == '#')
			flag->sharp = 1;
		if (param->flag[i] == '0')
			flag->zero = 1;
		if (param->flag[i] == ' ')
			flag->space = 1;
	}
	if (flag->plus == 1)
		flag->space = 0;
	if ((flag->minus == 1 || (param->presition != 0 && param->type != 's')))
		flag->zero = 0;
	if (param->type == 'u' || param->type == 'o' || param->type == 'x' || param->type == 'X')
	{
		flag->plus = 0;
		flag->space = 0;
	}
	if (param->type != 'o' || param->type != 'x' || param->type != 'X' || param->type != 'f')
		flag->sharp = 0;
//	printf("minus = %d, space = %d, plus = %d, sharp = %d, zero = %d\n",flag->minus, flag->space, flag->plus, flag->sharp, flag->zero);//
}

void	type_print(t_param *param, unsigned int *all_len)
{
	t_flags	flag;
	void	(*ptr_ints_f)(t_param *, unsigned int *, t_flags *) = NULL;

	flag_reset(&flag);
	init_flag(param, &flag);
	if (param->type == 'd' || param->type == 'i')
		ptr_ints_f = di_func;
	if (param->type == 'u' || param->type == 'o' || param->type == 'x' || param->type == 'X')
		ptr_ints_f = ouxX_func;
	if (param->type == 'f' || param->type == 'F')
		ptr_ints_f = fF_func;
	if (param->type == 'c' || param->type == 's')
		ptr_ints_f = c_func;
	if (param->type == 'p')
		ptr_ints_f = p_func;
	ptr_ints_f(param, all_len, &flag);
}
