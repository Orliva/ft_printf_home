#include "ft_printf.h"
/*
static	unsigned int ft_strlen(const char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
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
	/////////Функция которая смотри format на наличие специальных знаков
	/////////Создать указатель на функцию, и передавать агрументы
	while (*param.dup_format)
	{
		len++;
		while (*param.dup_format == '%')
		{
			init_param(&param, &len);
			printf(" fd = %d, flag = %s, width = %d, presition = %d,\nmod = %s, type = %c, spes_symb = %c\n", param.fd, param.flag, param.width, param.presition, param.mod,param.type, param.spesific_symb);
//			write(1, "start!!", 7);
			print_param(&param, &len);
//			write(1, "end!!", 5);
		//	printf("\n%s\n", param.dup_format);
			param.dup_format++;
		}
		write(param.fd, param.dup_format, 1);/////смешает ли write указатель в процессе отрисовки??????
		param.dup_format++;
	}
//	free_all(&param);
	va_end(param.arg);
	return (len);
}
