/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:47:46 by lulee             #+#    #+#             */
/*   Updated: 2020/03/01 22:45:32 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xX.h"

static	unsigned	long	long	int	ft_pow(unsigned long long int num, unsigned int count)
{
	while (count)
	{
		num *= 16;
		count--;
	}
	return (num);
}

static	char	ft_letter(t_param *param, unsigned char num)
{
	int	coef;

	if (param->type == 'x')
		coef = 0;
	else
		coef = -32;
	if (num == 10)
		return ('a' + coef);
	if (num == 11)
		return ('b' + coef);
	if (num == 12)
		return ('c' + coef);
	if (num == 13)
		return ('d' + coef);
	if (num == 14)
		return ('e' + coef);
	return ('f' + coef);
}

static	unsigned	int	final_part(t_param *param, unsigned long long int var, unsigned int count)
{
	unsigned	char	tmp;

	if ((param->s_presit == 1 && param->presition != 0) || param->s_presit == 0)
	{
		tmp = (var / ft_pow((unsigned long long int)1, count));
		if (tmp < 10)
			tmp += 48;
		else
			tmp = ft_letter(param, tmp);
		return (write(param->fd, &tmp, 1));
	}
	return (0);
}

unsigned	int	print_num_xX(t_param *param, unsigned long long int var)
{
	unsigned	int		count;
	unsigned	int		i;
	unsigned	char	tmp;

	i = 0;
	count = 0;
	if (param->count > 0)
		count = param->count - 1;
//	if (var == 0)
//		arg_is_zero(pr);
	while (count)
	{
		tmp = (var / ft_pow((unsigned long long int)1, count));
		if (tmp < 10)
			tmp += 48;
		else
			tmp = ft_letter(param, tmp);
		i += write(param->fd, &tmp, 1);
		var %= ft_pow((unsigned long long int)1, count);
		count--;
	}
	i += final_part(param, var, count);
	return (i);
}
