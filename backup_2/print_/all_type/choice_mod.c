/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:10:14 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 16:14:46 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

short	int	choice_mod(t_param *param)
{
	if (param->mod[0] != '\0')
	{
		if (compare("h", param->mod) == 0)
			return (H);
		if (compare("hh", param->mod) == 0)
			return (HH);
		if (compare("l", param->mod) == 0)
			return (L_DOWN);
		if (compare("ll", param->mod) == 0)
			return (LL_DOWN);
		if (compare("L", param->mod) == 0)
			return (L_UP);
	}
	return (NONE_MODE);
}
