#include "../ft_printf.h"

static	char	*mal(char *str, unsigned int len)
{
	if (!(str = (char *)malloc((sizeof (char)) * (len + 1))))
		ft_error_exit();//////MAY BE ERROR-NAMED
//	printf("len_mal = %d\n", len);
//	write(1, "Q", 1);
//	str[0] = '1';
//	write(1, &str[0], 1);
	str[len] = '\0';
	return (str);
}

char	*mall_width(t_param *param, unsigned int len, t_flags *flag)
{
	char *tmp;

	tmp = NULL;
	if (len < param->width)
		len = param->width;
	if (len < param->presition)
		len = param->presition;
	if (flag->sharp == '1')
	{
		if (param->type == 'x' || param->type == 'X')
			len += 2;
		if (param->type == 'o')
			len++;
	//	if (param->type == 'f')
	}
//	if (flag->plus == '1')
//		len++;
	if (flag->space == '1')
		len++;
	tmp = mal(tmp, len);
//	write(1, "may error?", 10);
//	tmp[0] = 'F';
//	write(1, &tmp[0], 1);
	param->len = len;
	return (tmp);
}
