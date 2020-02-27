#include "../include/ft_printf.h"

static	char	*mal(char *str, unsigned int len)
{
	if (!(str = (char *)malloc((sizeof (char)) * (len + 1))))
		ft_error_exit();
	str[len] = '\0';
	return (str);
}

char	*mall_width(t_param *param, unsigned int len, t_flags *flag, t_pr *pr)
{
	char *tmp;

//	printf("len = %u\n", len); ///
	tmp = NULL;
	pr->dop_mem = 0;
	if (flag->sharp == 1)
	{
		pr->dop_mem = param->width - param->presition == 1 && (param->type == 'x' || param->type == 'X' || param->type == 'p') ? 1 : 0;
//		pr->dop_mem = param->presition - param->width == 1 || param->presition - len == 1 ? 2 : 0;
		if (param->type == 'x' || param->type == 'X' || param->type == 'p')
			len += 2;
		if (param->type == 'o')
			len++;
	//	if (param->type == 'f')
	}
	if (len < param->presition)
		len = param->presition;
	if (flag->space == 1 || flag->plus == 1 || pr->sign == '-')
		len++;
	if (len < param->width)
		len = param->width;
	if (param->presition == len)
		if (flag->sharp == 1 && (param->type == 'x' || param->type == 'X' || param->type == 'p'))
			len += 2;
	len += pr->dop_mem;
//	printf("minus = %d, plus = %d, space = %d, zero = %d, sharp = %d, len = %u\n", flag->minus, flag->plus, flag->space, flag->zero, flag->sharp, len);
	if (len == 0)
		len++;
	tmp = mal(tmp, len);
	if (param->type == 'p')
		param->len = --len;
	else
		param->len = len;
//	printf("param->len = %u\n", param->len); ///
	return (tmp);
}
