/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 07:14:48 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 08:49:49 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/di.h"

static	long	long	int	ft_pow(long long int num, unsigned int count)
{
	while (count)
	{
		num *= 10;
		count--;
	}
	return (num);
}

static	unsigned	int		fin(t_param *param, long long int var)
{
	char	tmp;

	if ((param->n_presit == 1 &&
				(param->presition != 0)) || param->n_presit == 0)
	{
		tmp = var + 48;
		return ((unsigned int)write(param->fd, &tmp, 1));
	}
	return ((unsigned int)0);
}

static	long	long	int	negative_num(t_param *param, long long int var)
{
	if (param->count < 19 || (param->count == 19 && var % 10 != -8))
		var *= -1;
	return (var);
}

unsigned	int				print_num_di(t_param *param, long long int var)
{
	unsigned	int	count;
	unsigned	int	i;
	char			tmp;

	i = 0;
	count = 0;
	if (param->count > 0)
		count = param->count - 1;
	if (param->count == 19 && var % 10 == -8)
	{
		return ((unsigned int)write(param->fd, "9223372036854775808", 19));
	}
	if (var < 0)
		var = negative_num(param, var);
	while (count)
	{
		tmp = (var / ft_pow((long long int)1, count)) + 48;
		i += write(param->fd, &tmp, 1);
		var %= ft_pow((long long int)1, count);
		count--;
	}
	i += fin(param, var);
	return (i);
}
