#include "../ft_printf.h"

int	is_spesific_symb(t_param *param, unsigned int *all_len)
{
	if (*param->dup_format == '%')
	{
		all_len++;
		write(param->fd, "%", 1);
		param->dup_format++;
		return (1);
	}
	return (0);
}

void	is_type(t_param *param)
{
	if (*param->dup_format == 'd' || *param->dup_format == 'i' ||
		*param->dup_format == 'u' || *param->dup_format == 'o' ||
		*param->dup_format == 'x' || *param->dup_format == 'X' ||
		*param->dup_format == 'f' || *param->dup_format == 'F' ||
		*param->dup_format == 'e' || *param->dup_format == 'E' ||
		*param->dup_format == 'g' || *param->dup_format == 'G' ||
		*param->dup_format == 'a' || *param->dup_format == 'A' ||
		*param->dup_format == 'c' || *param->dup_format == 'p')
		param->type = *param->dup_format;
	param->dup_format++;
}
////diuoxXfFeEgGaAcp
