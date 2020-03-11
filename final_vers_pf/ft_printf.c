/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 08:20:45 by lulee             #+#    #+#             */
/*   Updated: 2020/03/05 20:06:32 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

static	char	*ft_strdup(const char *str)
{
	unsigned	int	i;
	char			*new_str;

	new_str = (char *)malloc(sizeof(char) *
			(ft_strlen((char *)str) + 1));
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static	void	init_par(t_param *param, const char *format)
{
	param->dup_format = NULL;
	param->flag = NULL;
	param->mod = NULL;
	param->dup_format = ft_strdup(format);
	param->fd = 1;
}

int				ft_printf(const char *format, ...)
{
	t_param			param;
	unsigned	int	len;
	char			*tmp;

	init_par(&param, format);
	tmp = param.dup_format;
	len = 0;
	va_start(param.arg, format);
	while (*param.dup_format)
	{
		while (*param.dup_format == '%')
		{
			if (init_param(&param, &len))
				type_print(&param, &len);
		}
		if (*param.dup_format)
		{
			len += write(param.fd, param.dup_format, 1);
			param.dup_format++;
		}
	}
	free(tmp);
	va_end(param.arg);
	return (len);
}
