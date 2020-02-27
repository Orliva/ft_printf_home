/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:46:15 by lulee             #+#    #+#             */
/*   Updated: 2020/02/27 17:55:06 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	left_pos_s(t_param *param, unsigned int *all_len, char *num)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (ft_strlen(num) < param->presition)
		len = ft_strlen(num);
	else
		len = param->presition;
//	if (param->s_presit == 0 && param->presition == 0)
//		param->presition = ft_strlen(num);
	while (len)
	{
		if (param->width > 0)
			param->width--;
		*all_len += write(param->fd, &num[i++], 1);
		len--;
	}
	while (param->width > len)
	{
		*all_len += write(param->fd, " ", 1);
		param->width--;
		if (param->presition > 0)
			param->presition--;
	}
}

static	void	right_pos_s(t_flags *flag, t_param *param, unsigned int *all_len, char *num)
{
	char	tmp;
	unsigned int	i;
	unsigned int 	len;

	if (ft_strlen(num) < param->presition)
		len = ft_strlen(num);
	else
		len = param->presition;
//	printf("len = %u\n", len);
	i = 0;
	tmp = flag->zero == 0 ? ' ' : '0';
//	if (param->s_presit == 0 && param->presition == 0)
//		param->presition = ft_strlen(num);
	while (param->width > len)
	{
		*all_len += write(param->fd, &tmp, 1);
		if (param->width > 0)
			param->width--;
	}
	while (len)
	{
		if (param->width > 0)
			param->width--;
		*all_len += write(param->fd, &num[i++], 1);
		len--;
	}
}


void			init_num_s(t_flags *flag, t_param *param, unsigned int *all_len, char *num)
{
	char	*tmp;
	if (num == NULL)///////Проверить как работает с NULL
		tmp = "(null)\0";
	else
		tmp = num;
//	printf("%s\n", tmp);
	if (param->s_presit == 0)
		param->presition = ft_strlen(tmp);
	if (flag->minus == 1)
		left_pos_s(param, all_len, tmp);
	else
	{
		right_pos_s(flag, param, all_len, tmp);
	}
}
