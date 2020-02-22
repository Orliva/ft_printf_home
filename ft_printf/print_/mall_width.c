#include "../ft_printf.h"

static	void	mal(char *str, unsigned int len)
{
	if (!(str = (char *)malloc((sizeof (char)) * (len + 1))))
		ft_error_exit();//////MAY BE ERROR-NAMED
	str[len] = '\0';
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
	mal(tmp, len);
	param->len = len;
	return (tmp);
}
