#include "../ft_printf.h"

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
	write(1, "0", 1);
	free(param->flag);

	write(1, "1", 1);
}

void	is_flag(t_param *param)
{
	int len;
	char *tmp;

	len = 0;
	if(!(param->flag = (char *)malloc(sizeof(char) * (len + 1))))
		ft_error_exit();////no writed
	*param->flag = '\0';
	while (*param->dup_format && (*param->dup_format == '-' || *param->dup_format == '+' ||
		*param->dup_format == ' ' || *param->dup_format == '0' ||
		*param->dup_format == '#'))
	{
		len++;
		tmp = (char *)malloc(sizeof(char) * (len + 1));
		rewrite_flag(param, tmp);
		param->flag = tmp;
		param->dup_format++;
	}
//	write(1, "sucsess flag", 12);
}


////динамически выделить память под количество флагов
///len для количества флагов
///потом читать массив символов *flag и в зависимости от флагов выполнять функции 
/// под каждый флаг

