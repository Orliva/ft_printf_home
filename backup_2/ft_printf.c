#include "./include/ft_printf.h"

static	char	*ft_strdup(const char *str)
{
	unsigned int i;
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen((char *)str) + 1));
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_printf(const char *format, ...)
{
	t_param	param;
	unsigned int	len;

	len = 0;
	param.dup_format = ft_strdup(format);
	param.fd = 1;
	va_start(param.arg, format);
	while (*param.dup_format)
	{
		len++;
		while (*param.dup_format == '%')
		{
			if (init_param(&param, &len))
//			printf(" fd = %d, flag = %s, width = %d, presition = %d,\nmod = %s, type = %c, spes_symb = %c\n", param.fd, param.flag, param.width, param.presition, param.mod,param.type, param.spesific_symb);
				type_print(&param, &len);
		}
		if (*param.dup_format)
		{
			write(param.fd, param.dup_format, 1);
			param.dup_format++;
		}
	}
//	free_all(&param);
	va_end(param.arg);
//	len--;/////Временное решение, где то лишний раз прибавляется *all_len
	return (len);
}
