/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:09:56 by lulee             #+#    #+#             */
/*   Updated: 2020/02/26 17:56:50 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putstr_fd(char *print, t_param *param, unsigned int *all_len)
{
	while (*print)
	{
		write(param->fd, &*print++, 1);
		(*all_len)++;
	}
	(*all_len)--;///////будет вычитать лишнюю единицу, если в *print 1 цифра
}

unsigned int count_num_min(unsigned long long int num, t_param *param)
{
	unsigned int count;
	unsigned int cof;

	cof = 10;
	if (param->type == 'x' || param->type == 'X')
		cof = 16;
	if (param->type == 'o')
		cof = 8;
	count = 0;
	while (num)
	{
		num /= cof;
		count++;
	}
	return (count);
}

unsigned int count_num_pl(long long int num)
{
	unsigned int count;

	count = 0;
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	return (0);
}

unsigned int ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
