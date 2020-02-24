#include "../ft_printf.h"

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

	printf("len = %u\n", len);
	tmp = NULL;
	if (len < param->presition)
		len = param->presition;
	if (flag->space == 1 || flag->plus == 1 || pr->sign == '-')
		len++;
	if (len < param->width)
		len = param->width;
	if (flag->sharp == 1)
	{
		if (param->type == 'x' || param->type == 'X')
			len += 2;
		if (param->type == 'o')
			len++;
	//	if (param->type == 'f')
	}
//	printf("minus = %d, plus = %d, space = %d, zero = %d, sharp = %d, len = %u\n", flag->minus, flag->plus, flag->space, flag->zero, flag->sharp, len);
	tmp = mal(tmp, len);
	param->len = len;
	printf("param->len = %u\n", param->len);
	return (tmp);
}
