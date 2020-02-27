/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:13:18 by lulee             #+#    #+#             */
/*   Updated: 2020/02/26 17:14:29 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_error_exit()
{
	exit(-1);
}

static	void	rewrite_flag(t_param *param, char *tmp)
{
	unsigned int i;

	i = 0;
	while (param->flag[i])
	{
		tmp[i] = param->flag[i];
		i++;
	}
	tmp[i] = *param->dup_format;
	tmp[i + 1] = '\0';
	free(param->flag);
}

void	is_flag(t_param *param)///////Возможно тут утечка?
				////Вроде все ок, но возможно поменять tmp и param->flag
{
	int len;
	char *tmp;

	len = 0;
	if(!(param->flag = (char *)malloc(sizeof(char) * (len + 1))))
		ft_error_exit();
	*param->flag = '\0';
	while (*param->dup_format && (*param->dup_format == '-' ||
		*param->dup_format == '+' || *param->dup_format == ' ' ||
		*param->dup_format == '0' || *param->dup_format == '#'))
	{
		len++;
		if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
			ft_error_exit();
		rewrite_flag(param, tmp);
		param->flag = tmp;
		param->dup_format++;
	}
}
