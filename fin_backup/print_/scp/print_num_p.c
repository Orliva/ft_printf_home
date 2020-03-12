/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:08:58 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 09:23:18 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/scp.h"

static	unsigned	long	long	int	ft_pow(unsigned long long int num,
		unsigned int count)
{
	while (count)
	{
		num *= 16;
		count--;
	}
	return (num);
}

static	char							ft_letter(unsigned char num)
{
	if (num == 10)
		return ('a');
	if (num == 11)
		return ('b');
	if (num == 12)
		return ('c');
	if (num == 13)
		return ('d');
	if (num == 14)
		return ('e');
	return ('f');
}

static	unsigned	int					final_part(t_param *param,
		unsigned long long int var)
{
	unsigned	char	tmp;

	if ((param->n_presit == 1 && param->presition != 0) || param->n_presit == 0)
	{
		tmp = var;
		if (tmp < 10)
			tmp += 48;
		else
			tmp = ft_letter(tmp);
		return (write(param->fd, &tmp, 1));
	}
	return (0);
}

static	void							del_zero(unsigned int *count,
		unsigned long long int var)
{
	unsigned	char	tmp;

	while (count)
	{
		tmp = (var / ft_pow((unsigned long long int)1, *count));
		if (tmp == 0)
		{
			var %= ft_pow((unsigned long long int)1, *count);
			(*count)--;
		}
		else
			break ;
	}
}

unsigned	int							print_num_p(t_param *param,
		unsigned long long int var)
{
	unsigned	int		count;
	unsigned	int		i;
	unsigned	char	tmp;

	i = 0;
	count = 0;
	if (param->count > 0)
		count = param->count - 1;
	if (var)
		del_zero(&count, var);
	while (count)
	{
		tmp = (var / ft_pow((unsigned long long int)1, count));
		if (tmp < 10)
			tmp += 48;
		else
			tmp = ft_letter(tmp);
		i += write(param->fd, &tmp, 1);
		var %= ft_pow((unsigned long long int)1, count);
		count--;
	}
	i += final_part(param, var);
	return (i);
}
