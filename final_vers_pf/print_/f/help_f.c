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
#include <stdio.h>

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

int				rounding_f(t_pr *pr, t_param *param, long double *var)
{
	if (pr->num[pr->i] != '.')
		pr->i--;
//	else
//		*var = 
//	printf("%c %d\n", pr->num[pr->i], (int)*var);
	if ((int)(*var) < 5)
		return (0);
	else
	{
		if (pr->num[pr->i] == '.')
			pr->i--;
		pr->num[pr->i]++;
		while (pr->num[pr->i] == 58 || pr->num[pr->i] == '.')
		{
			if (pr->num[pr->i] != '.')
				pr->num[pr->i] = '0';
			if (pr->i > 0)
				pr->i--;
			if (pr->num[pr->i] == '.')
				pr->i--;
			pr->num[pr->i]++;
			if (pr->i == 0 && pr->num[pr->i] == 58)
			{
				param->spesific_symb = -1;
				pr->num[pr->i] = '0';
				return (-1);
			}
		}
	}
	return (1);
}

