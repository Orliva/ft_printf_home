/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:12:44 by lulee             #+#    #+#             */
/*   Updated: 2020/02/26 17:13:11 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

////удалить free_all
void	free_all(t_param *param)//////Обнулять len, width, presi и тд
{
	free(param->dup_format);
//	free(&param->buff_dest);
	free(param->flag);
	free(param->mod);
//	free(&param->spesific_symb);
}

int	init_param(t_param *param, unsigned int *all_len)
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
