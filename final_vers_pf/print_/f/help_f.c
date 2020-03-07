/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:20:16 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 19:20:17 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ff.h"

unsigned	int	count_num_f(long double var)
{
	unsigned int count;

	count = 0;
	while ((int)(var / 10) != 0)
	{
		count++;
		var /= 10;
	}
	count++;
	return (count);
}

long	double	ft_pow_lld(long double num, unsigned int count)
{
	while (count)
	{
		num *= 10;
		count--;
	}
	return (num);
}
