/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_seg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:19:16 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 08:33:15 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	int	prot_type(char *tmp)
{
	if (*tmp == 'd' || *tmp == 'i' || *tmp == 'u' || *tmp == 'o' ||
			*tmp == 'x' || *tmp == 'X' || *tmp == 'f' || *tmp == 'F' ||
			*tmp == 'c' || *tmp == 's' || *tmp == 'p')
		return (1);
	return (0);
}

static	int	prot_mod(char *tmp)
{
	if (*tmp == 'h' || *tmp == 'l' || *tmp == 'L')
	{
		tmp++;
		while (*tmp == 'h' || *tmp == 'l' || *tmp == 'L')
			tmp++;
		return (prot_type(tmp));
	}
	else
		return (prot_type(tmp));
}

static	int	prot_width(char *tmp)
{
	if ((*tmp >= '0' && *tmp <= '9') || *tmp == '.')
	{
		tmp++;
		while ((*tmp >= '0' && *tmp <= '9') || *tmp == '.')
			tmp++;
		return (prot_mod(tmp));
	}
	else
		return (prot_mod(tmp));
	return (0);
}

int			protect_seg(char *str)
{
	char *tmp;

	tmp = str;
	while (*tmp != '%' && *tmp)
	{
		if (*tmp != '-' && *tmp != '+' &&
				*tmp != ' ' && *tmp != '0' && *tmp != '#')
			return (prot_width(tmp));
		else
			tmp++;
	}
	return (0);
}
