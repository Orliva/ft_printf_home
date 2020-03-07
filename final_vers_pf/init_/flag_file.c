/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:12:06 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 19:31:37 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			ft_error_exit(void)
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
}

void			is_flag(t_param *param)
{
	int		len;
	char	*tmp;
	char	*tmp_2;

	len = 0;
	tmp = NULL;
	tmp_2 = NULL;
	if (!(param->flag = (char *)malloc(sizeof(char) * (len + 1))))
		ft_error_exit();
	*param->flag = '\0';
	tmp_2 = param->flag;
	while (*param->dup_format && (*param->dup_format == '-' ||
		*param->dup_format == '+' || *param->dup_format == ' ' ||
		*param->dup_format == '0' || *param->dup_format == '#'))
	{
		len++;
		if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
			ft_error_exit();
		tmp[len] = '\0';
		rewrite_flag(param, tmp);
		param->flag = tmp;
		param->dup_format++;
	}
}
